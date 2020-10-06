#include	"enemy.h"

#include	"framework.h"
#include	"player.h"


extern	Player player;

/*******************************************************************************
	「敵」クラスのメンバ関数
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
	//	行動を確率で分岐
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

	case 2:		//	直進_処理(向いている方向へ前進)
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
	//case INITIALIZE:		//	初期化
	//	state++;
	//	//		break;
	//case SELECT:
	//{
	//	//	こういう組み方もある
	//	//	以下の配列などはswitchの外で宣言しても良いが、
	//	//	ここに配置する場合は"{}"を使う事でブロック変数として
	//	//	用意する必要がある
	//	int	rateSelect[] = { 50, 25, 20,  5, -1 };
	//	int rate, rateSum = 0;
	//	int n = 0;

	//	rate = rand() % 100;
	//	while (rateSelect[n] != -1)
	//	{
	//		rateSum += rateSelect[n];
	//		if (rate < rateSum)
	//		{
	//			state = WAIT_INIT + n * 2;			//	1行で実装してみる
	//			break;
	//		}
	//		n++;
	//	}
	//}
	//break;
	//case WAIT_INIT:			//	待機_初期化
	//	timer = 2 * FRAME_RATE;
	//	state++;
	//	//break;
	//case WAIT_PROC:			//	待機_処理(2秒後次のモードへ)
	//	timer--;
	//	if (timer < 0)		state	= SELECT;	//	行動選択へ
	//	break;

	//case STRAIGHT_INIT:		//	直進_初期化
	//	timer = 3 * FRAME_RATE;
	//	state++;
	//	//break;
	//case STRAIGHT_PROC:		//	直進_処理(向いている方向へ前進)
	//	pos.x += sinf(angle) * speed;
	//	pos.z += cosf(angle) * speed;

	//	timer--;
	//	if (timer < 0)		state	= SELECT;	//	行動選択へ
	//	break;

	//case ROTATE_INIT:		//	旋回_初期化
	//	timer = 5 * FRAME_RATE;
	//	state++;
	//	//break;
	//case ROTATE_PROC:		//	旋回_処理(右回りに旋回)
	//	angle += dangle;					//	回転

	//	pos.x += sinf(angle) * speed;		//	直進
	//	pos.z += cosf(angle) * speed;		//

	//	timer--;
	//	if (timer < 0)		state	= SELECT;	//	行動選択へ
	//	break;
	//case TARGET_INIT:		//	プレイヤーへ直進_初期化
	//	timer = 3 * FRAME_RATE;
	//	angle = atan2f(player.pos.x - pos.x, player.pos.z - pos.z);					//	回転
	//	state++;
	//	//break;
	//case TARGET_PROC:		//	プレイヤーへ直進_処理(右回りに旋回)

	//	pos.x += sinf(angle) * speed;		//	直進
	//	pos.z += cosf(angle) * speed;		//

	//	timer--;
	//	if (timer < 0)		state	= SELECT;	//	行動選択へ
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
	「敵管理」クラスのメンバ関数
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