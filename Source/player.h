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

	bool                jumpFlg = false;
	float               accele = 0.1f;
	int                 gravity = 1;

	void    Jump();

	void	Initialize( const char* );																							//	初期化関数
	void	Release();																											//	解放関数
	void	Move();																												//	移動関数
	void	Render( const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir );	//	描画関数
};