#include	"player.h"

#include	"shot.h"
#include	"particle.h"

void Player::Jump()
{
	pos.y = pos.y + accele * gravity;
	accele += 0.05f;
	if (pos.y > 4.0f)
	{
		pos.y = 4.0f;
		accele = 0.1f;
		jumpFlg = false;
	}
	if (pos.y < 0.0f)
	{
		pos.y = 0.0f;
		accele = 0.1f;
		jumpFlg = false;
	}
}

/*******************************************************************************
	「プレイヤー」クラスの初期化
*******************************************************************************/
void	Player::Initialize(const char* filename)
{
	obj.Initialize();
	obj.Load( filename );
	pos = { -2, 0, -5 };
}


/*******************************************************************************
	「プレイヤー」クラスの解放
*******************************************************************************/
void	Player::Release()
{
	obj.Release();
}


/*******************************************************************************
	「プレイヤー」クラスの描画
*******************************************************************************/
void	Player::Render( const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir )
{
	obj.pos		= this->pos;
	obj.angle.y = this->angle;

	obj.Render(view, projection, light_dir);
}


/*******************************************************************************
	「プレイヤー」クラスの移動
*******************************************************************************/
void	Player::Move()
{
	//const float dangle	= DirectX::XMConvertToRadians( 1.0f );		//	1度
	//const float speed	= 0.05f;									//	プレイヤーの速度

	//	回転
	//if (GetAsyncKeyState(VK_LEFT)  < 0)	angle -= dangle;
	//if (GetAsyncKeyState(VK_RIGHT) < 0)	angle += dangle;

	//if (GetAsyncKeyState(VK_UP) < 0)
	//{
	//	float dx = sinf(angle);			//	移動ベクトル(X成分)
	//	float dz = cosf(angle);			//	移動ベクトル(Z成分)
	//	pos.x += dx * speed;
	//	pos.z += dz * speed;
	//}

	//　プレイヤーの（瞬間）移動
	if (GetAsyncKeyState(VK_LEFT))
	{
		pos.x -= 0.1;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		pos.x += 0.1;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		pos.z += 0.05f;
	}

	Jump();

	if (GetAsyncKeyState(' ') & 1)
	{
		if (jumpFlg == false)
		{
			gravity *= -1;
			jumpFlg = true;
		}
	}

	////	弾丸発射処理
	//if (GetAsyncKeyState(' ') & 1)
	//{
	//	const float	SHOT_SPEED = 0.5f;
	//	const float OFS_FRONT = 0.45f;
	//	const float OFS_HEIGHT = 0.55f;

	//	DirectX::XMFLOAT3 p = pos;
	//	p.x += sinf(angle) * OFS_FRONT;
	//	p.z += cosf(angle) * OFS_FRONT;
	//	p.y += OFS_HEIGHT;
	//	shotManager.Set(p, angle, SHOT_SPEED, 0.2f);

	//	//	パーティクル管理クラスの設置関数の呼び出し(実験用)
	//	//pParticleManager->Set(p, 1.0f, DirectX::XMFLOAT4(0.8f, 0.4f, 0.2f, 0.6f));

	//	/*******************************************************************************
	//		パーティクルを用いた演出(砲撃の際に発生する火花っぽい物)
	//	*******************************************************************************/
	//	for (int n = 0; n < 5; n++)
	//	{
	//		DirectX::XMFLOAT3	vec, power;
	//		static const float	MUZZLE_SPEED = SHOT_SPEED*0.4f;
	//		static const float SCALE = 0.05f;
	//		static const DirectX::XMFLOAT4 COLOR(0.8f, 0.4f, 0.2f, 0.5f);

	//		vec.x = ((rand() % 2001) - 1000) * 0.00002f + sinf(angle)*MUZZLE_SPEED;
	//		vec.z = ((rand() % 2001) - 1000) * 0.00002f + cosf(angle)*MUZZLE_SPEED;
	//		vec.y = ((rand() % 2001) - 1000) * 0.00002f;

	//		power.x = 0.0f;
	//		power.z = 0.0f;
	//		power.y = -0.002f;

	//		pParticleManager->Set(p, vec, power, SCALE, COLOR, 5);
	//	}

	//}

}