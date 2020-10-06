#pragma once

#include	<DirectXMath.h>

#include	"my_mesh.h"

/*******************************************************************************
	「敵」クラス
*******************************************************************************/
class Stage
{
public:
	MyMesh				obj;		//	「モデルオブジェクト」
	DirectX::XMFLOAT3	pos;		//	「位置(座標)」
	float				angle;		//	「回転角度」

	DirectX::XMFLOAT4	color;		//	「色」
	bool				exist;		//	「存在フラグ」


	//	敵クラスに情報を追加
	int					state;		//	「状態」
	int					timer;		//	「タイマー」

	void	Initialize(const char*);																							//	初期化関数

	void	Release();																											//	解放関数
	void	Move();																												//	移動関数
	void	Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir); 	//	描画関数
	
};


/*******************************************************************************
	「敵管理」クラス
*******************************************************************************/
class EnemyManager
{
public:
	static const int	MAX = 32;				//	「最大数」	

private:
	Enemy				data[MAX];				//	「敵データ」


public:
	void	Initialize();																										//	初期化関数
	void	Release();																											//	解放関数
	void	Update();																											//	更新関数
	void	Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir);	//	描画関数

	Enemy* Set(const char* filename, DirectX::XMFLOAT3 pos, float angle, DirectX::XMFLOAT4 color);								//	敵設定関数
	Enemy* EnemyManager::Set(MyMesh& mesh, DirectX::XMFLOAT3 pos, float angle, DirectX::XMFLOAT4 color);

	Enemy* Get(int no) {
		if ((unsigned int)no >= MAX)	return	nullptr;
		return		&data[no];
	}

};

extern	EnemyManager	enemyManager;		//	こっそり追加
