#pragma once

#include	<DirectXMath.h>

#include	"my_mesh.h"



/*******************************************************************************
	「プレイヤー」クラス
*******************************************************************************/
class Player
{
public:
	MyMesh				obj;				//	「モデルオブジェクト」
	DirectX::XMFLOAT3	pos;				//	「位置(座標)」
	float				angle;				//	「回転角度」

	DirectX::XMFLOAT3   pre_pos;			// previous_position

	bool                jumpFlg = true;
	float               accele = 0.3f;
	float				speed = 0.1f;       // 横方向の移動変数
	int                 gravity = 1;

	bool                skyFlg;
	bool                groundFlg;
	bool                deathFlg = false;
	bool				resetFlg = false;

	bool				clearFlg = false;

	float               Vertical_movement;
	   
	void    Jump();
	void	Move();																												//	移動関数

	void	Initialize();																										//	初期化関数
	//void	Initialize( const char* );																							//	初期化関数
	void	Release();																											//	解放関数
	void    Update();
	void	Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir);	//	描画関数
};