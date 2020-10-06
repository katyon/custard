#include	"enemy.h"

#include	"framework.h"
#include	"player.h"


extern	Player player;

/*******************************************************************************
	�u�G�v�N���X�̃����o�֐�
*******************************************************************************/
void	Enemy::Initialize(const char* filename)
{
	obj.Initialize();
	obj.Load( filename );

	state = INITIALIZE;
	timer = 0;
}

void	Enemy::Release()
{
	obj.Release();
}

void	Enemy::Move()
{
	//	�s�����m���ŕ���
	const float dangle	= DirectX::XMConvertToRadians(1.0f);
	float speed	= 0.30f;
	//if ()
	//{

	//}

	switch ( state )
	{
	case 0:
		state++;
		break;

	case 1: 
		//timer = 3 * FRAME_RATE;
		timer = 0;
		state++;
		break;

	case 2:		//	���i_����(�����Ă�������֑O�i)
		timer++;
		pos.x += sinf(angle) * speed;
		pos.z += cosf(angle) * speed;

		if (pos.z < -5.0)
		{
			exist = false;
		}
		break;
	}

	//switch( state )
	//{
	//case INITIALIZE:		//	������
	//	state++;
	//	//		break;
	//case SELECT:
	//{
	//	//	���������g�ݕ�������
	//	//	�ȉ��̔z��Ȃǂ�switch�̊O�Ő錾���Ă��ǂ����A
	//	//	�����ɔz�u����ꍇ��"{}"���g�����Ńu���b�N�ϐ��Ƃ���
	//	//	�p�ӂ���K�v������
	//	int	rateSelect[] = { 50, 25, 20,  5, -1 };
	//	int rate, rateSum = 0;
	//	int n = 0;

	//	rate = rand() % 100;
	//	while (rateSelect[n] != -1)
	//	{
	//		rateSum += rateSelect[n];
	//		if (rate < rateSum)
	//		{
	//			state = WAIT_INIT + n * 2;			//	1�s�Ŏ������Ă݂�
	//			break;
	//		}
	//		n++;
	//	}
	//}
	//break;
	//case WAIT_INIT:			//	�ҋ@_������
	//	timer = 2 * FRAME_RATE;
	//	state++;
	//	//break;
	//case WAIT_PROC:			//	�ҋ@_����(2�b�㎟�̃��[�h��)
	//	timer--;
	//	if (timer < 0)		state	= SELECT;	//	�s���I����
	//	break;

	//case STRAIGHT_INIT:		//	���i_������
	//	timer = 3 * FRAME_RATE;
	//	state++;
	//	//break;
	//case STRAIGHT_PROC:		//	���i_����(�����Ă�������֑O�i)
	//	pos.x += sinf(angle) * speed;
	//	pos.z += cosf(angle) * speed;

	//	timer--;
	//	if (timer < 0)		state	= SELECT;	//	�s���I����
	//	break;

	//case ROTATE_INIT:		//	����_������
	//	timer = 5 * FRAME_RATE;
	//	state++;
	//	//break;
	//case ROTATE_PROC:		//	����_����(�E���ɐ���)
	//	angle += dangle;					//	��]

	//	pos.x += sinf(angle) * speed;		//	���i
	//	pos.z += cosf(angle) * speed;		//

	//	timer--;
	//	if (timer < 0)		state	= SELECT;	//	�s���I����
	//	break;
	//case TARGET_INIT:		//	�v���C���[�֒��i_������
	//	timer = 3 * FRAME_RATE;
	//	angle = atan2f(player.pos.x - pos.x, player.pos.z - pos.z);					//	��]
	//	state++;
	//	//break;
	//case TARGET_PROC:		//	�v���C���[�֒��i_����(�E���ɐ���)

	//	pos.x += sinf(angle) * speed;		//	���i
	//	pos.z += cosf(angle) * speed;		//

	//	timer--;
	//	if (timer < 0)		state	= SELECT;	//	�s���I����
	//	break;
	//}
}

//void Enemy::ExistFlg()
//{
//	int existTimer = 0;
//	existTimer++;
//	for (auto& d : data)
//	{
//		if (existTimer == 2)
//		{
//			d.exist = false;
//		}
//	}
//}

void	Enemy::Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir)
{
	obj.pos		= this->pos;
	obj.angle.y = this->angle;
	obj.color	= this->color;

	obj.Render(view, projection, light_dir);
}



bool EnemyManager::AP()
{
	for (int i = 0; i < MAX; i++)
	{
		if (data[i].exist)
		{
			return 0;
		}
	}
	return 1;
}

/*******************************************************************************
	�u�G�Ǘ��v�N���X�̃����o�֐�
*******************************************************************************/
void	EnemyManager::Initialize()
{
	for (auto& d : data)	d.exist = false;
}

void	EnemyManager::Release()
{
	for (auto& d : data)
	{
		if(d.exist)
			d.Release();
	}
}

void	EnemyManager::Update()
{
	for (auto& d : data)
	{
		if (d.exist)
		{
			d.Move();
			//d.ExistFlg();
		}
	}
}

void	EnemyManager::Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir)
{
	for (auto& d : data)
	{
		if(d.exist)	d.Render(view, projection, light_dir);
	}
}

Enemy*	EnemyManager::Set( const char* filename, DirectX::XMFLOAT3 pos, float angle, DirectX::XMFLOAT4 color)
{
	for (auto& d : data)
	{
		if (d.exist)	continue;

		d.Initialize( filename );
		d.pos	= pos;
		d.angle	= angle;
		d.color	= color;
		d.exist = true;
		return	&d;
	}

	return	nullptr;
}

Enemy* EnemyManager::Set(MyMesh& mesh, DirectX::XMFLOAT3 pos, float angle, DirectX::XMFLOAT4 color)
{
	for (auto& d : data)
	{
		if (d.exist)	continue;

		//d.Initialize(filename);
		d.obj.Initialize();
		d.obj.SetMesh(mesh);
		d.pos = pos;
		d.angle = angle;
		d.color = color;
		d.exist = true;
		return	&d;
	}

	return	nullptr;
}

//void EnemyManager::ExistFlg()
//{
//	for (auto& d : data)
//	{
//		if (!d.exist) continue;
//
//		d.existTimer--;
//		if (d.existTimer < 0)
//		{
//			d.exist = false;
//		}
//	}
//}