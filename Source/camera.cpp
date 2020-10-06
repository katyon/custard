#include	"camera.h"

#include	"framework.h"
#include	"player.h"
#include	"Util.h"

extern	Player	player;

/*******************************************************************************
	�u�J�����v�N���X�̃R���X�g���N�^
*******************************************************************************/
Camera::Camera()
{
	pos = DirectX::XMFLOAT3(.0f, 10.0f, -15.0f);
	target = DirectX::XMFLOAT3(.0f, .0f, .0f);

	float	fov = DirectX::XMConvertToRadians(30.0f);
	float	aspect = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
	SetPerspectiveMatrix( fov, aspect, 0.1f, 1000.0f );

	mode = MODE::WATCH;
}


/*******************************************************************************
	���s���e�s����Z�o����֐�
*******************************************************************************/
DirectX::XMMATRIX	Camera::SetOrthographicMatrix( float w, float h, float znear, float zfar )
{
	projection = DirectX::XMMatrixOrthographicLH( w, h, znear, zfar );
	return	projection;
}


/*******************************************************************************
	�������e�s����Z�o����֐�
*******************************************************************************/
DirectX::XMMATRIX	Camera::SetPerspectiveMatrix( float fov, float aspect, float znear, float zfar )
{
	projection = DirectX::XMMatrixPerspectiveFovLH( fov, aspect, znear, zfar );
	return	projection;
}


/*******************************************************************************
	�r���[�s����擾����֐�
*******************************************************************************/
DirectX::XMMATRIX	Camera::GetViewMatrix()
{
	DirectX::XMVECTOR	p	= DirectX::XMVectorSet( pos.x, pos.y, pos.z, 1.0f );
	DirectX::XMVECTOR	t	= DirectX::XMVectorSet( target.x, target.y, target.z, 1.0f );
	DirectX::XMVECTOR	up	= DirectX::XMVectorSet( 0.0f, 1.0f, 0.0f, 0.0f );

	return	DirectX::XMMatrixLookAtLH( p, t, up );
}


/*******************************************************************************
	�J�����p�X�V�֐��̎���
*******************************************************************************/
void	Camera::Update()
{
	//	�J�����̍X�V
	switch( mode )
	{
	case WATCH:			Watch();		break;		//	�u�Ď��J�����v
	case DIRECTIONAL:	Directional();	break;		//	�u���Έʒu�Œ�J�����v
	case CHASE:			Chase();		break;		//	�u�ǐՃJ�����v
	case TPS:			Tps();			break;		//	�u3�l�̃J����(TPS)�v
	case FPS:			Fps();			break;		//	�u1�l�̃J����(FPS)�v
	}


	//	�J�����̐؂�ւ�
	if (GetAsyncKeyState('C') & 1)
	{
		mode = (mode + 1) % MODE::MAX;		//	1�s�ł���������
		//	�����s�Ȃ炱�ꂪ����?
		//mode++;
		//if (mode <= MODE::MAX)	mode = WATCH;
	}


	////	�J�������[�h�m�F�p�f�o�b�O
	//char	str[64];
	//sprintf_s(str, 64, "CameraMode:%d", mode);
	//SetText(str, 5, 5);
}


/*******************************************************************************
	�u�Ď��J�����v�̎���
*******************************************************************************/
void	Camera::Watch()
{
	pos = DirectX::XMFLOAT3(.0f, 10.0f, -20.0f);
	//target = player.pos;
}
/*******************************************************************************
	�u���Έʒu�Œ�J�����v�̎���
*******************************************************************************/
void	Camera::Directional()
{
	pos.x = player.pos.x + 8.0f;
	pos.y = player.pos.y + 5.0f;
	pos.z = player.pos.z - 8.0f;

	target = player.pos;
}
/*******************************************************************************
	�u3�l�̃J�����v�̎���
*******************************************************************************/
void	Camera::Tps()
{
	const float	Distance = 12.0f;

	float	dx = sinf(player.angle);
	float	dz = cosf(player.angle);

	pos.x = player.pos.x - Distance * dx;
	pos.z = player.pos.z - Distance * dz;

	target = player.pos;
}
/*******************************************************************************
	�u1�l�̃J�����v�̎���
*******************************************************************************/
void	Camera::Fps()
{
	const float	Height = 0.75f;

	float	dx = sinf(player.angle);
	float	dz = cosf(player.angle);

	pos.x = player.pos.x;
	pos.y = player.pos.y + Height;
	pos.z = player.pos.z;

	target.x = pos.x + dx;
	target.y = pos.y;
	target.z = pos.z + dz;
}
/*******************************************************************************
	�u�ǐՃJ�����v�̎���
*******************************************************************************/
void	Camera::Chase()
{
	const float	minDistance =  5.0f;
	const float	maxDistance = 15.0f;

	float	dx = player.pos.x - pos.x;
	float	dz = player.pos.z - pos.z;
	float	distance = sqrtf(dx*dx + dz*dz);

	if (distance < minDistance)
	{
		dx /= distance;		//	�x�N�g���̐��K��
		dz /= distance;		//	
		pos.x = player.pos.x - minDistance * dx;
		pos.z = player.pos.z - minDistance * dz;
	}
	if (distance > maxDistance)
	{
		dx /= distance;		//	�x�N�g���̐��K��
		dz /= distance;		//	
		pos.x = player.pos.x - maxDistance * dx;
		pos.z = player.pos.z - maxDistance * dz;
	}

	target = player.pos;
}
