#include	"game.h"
#include	"framework.h"

#include	"my_mesh.h"
#include	"player.h"
#include	"camera.h"
#include	"particle.h"

#include	"collision.h"

#include    "sprite.h"

#include    "stage.h"

#include	<time.h>

/*******************************************************************************
	グローバル変数
*******************************************************************************/
//MyMesh			field;				//	地面用変数「地面」
Player			player;				//	プレイヤー用変数「プレイヤー」
Camera			camera;				//	カメラ用変数「カメラ」

Stage           stage;

//MyMesh          endLine;

//MyMesh          ball;

Text            text;

/*******************************************************************************
TODO:07 WAVE管理クラスの呼び出し
説明    Gameクラスの各所でWAVE管理クラスのメソッドを呼び出す
--------------------------------------------------------------------------------
手順    Gameクラスの各所で以下の処理を実行せよ
		・Game::Initialize関数でWAVE管理クラスの初期化関数を呼び出す
		　この時、引数はTODO_06で追加したデータとする
		・Game::Initialize関数で以前からあった敵出現処理をコメント化する
		　(敵出現はWAVE管理クラスに一元化する為、不要となる)
		・Game::Update関数でWAVE管理クラスの生成関数を呼び出す
		　この時、敵の更新よりも前に行った方が安定する
		・Game::Update関数で(使われていない)何かのキーを押した時に
		　WAVE管理クラスのWAVE進行関数を呼び出す
確認	起動時に敵が3体出現し、設定したキーを押す度に敵が2体→3体と出現すればOK
*******************************************************************************/

/*******************************************************************************
TODO:09 WAVE全滅検知に伴う増援呼び出し
説明    敵の現WAVE全滅を確認したら、次のWAVEを呼び出すように作成する
--------------------------------------------------------------------------------
手順    Game::Update関数内で、敵の全滅を検知したらWAVEが
		進行されるように変更する
		この際、TODO_07で行っていた「キー押したらWAVE進行」を
		削除しておく事
確認	敵を全滅させる毎に次のWAVEが進行され、最終WAVEを全滅させても
		特に問題が無ければOK
*******************************************************************************/


void	Game::Initialize()
{

	score = 0;

	srand((unsigned)time(NULL));

	//	投影変換行列
	projection = camera.GetProjectionMatrix();

	//	光源(平行光)
	light_direction = DirectX::XMFLOAT4(0, -1, 1, 0);		//	上+奥 から 下+前へのライト


	//	「地面」を初期化
	//field.Initialize();
	//field.SetPrimitive( new GeometricRect( FRAMEWORK.getDevice() ) );
	//field.color = DirectX::XMFLOAT4(0.5f, 1.0f, 0.4f, 1.0f);
	//field.scale = DirectX::XMFLOAT3(16.0f, 20.0f, 70.0f);

	//　線を表示  /////////////////////////////////////////////////
	//endLine.Initialize();
	//endLine.SetPrimitive(new GeometricRect(FRAMEWORK.getDevice()));
	//endLine.color = DirectX::XMFLOAT4(1.0f, 0.5f, 0.4f, 1.0f);
	//endLine.scale = DirectX::XMFLOAT3(16.0f, 20.0f, 2.0f);
	//endLine.pos = { 0.0f, 0.1f, -5.0f };
	//////////////////////////////////////////////////////////////

	//	「地面」を初期化
	//field.Initialize();
	//field.SetPrimitive(new GeometricRect(FRAMEWORK.getDevice()));
	//field.color = DirectX::XMFLOAT4(0.5f, 1.0f, 0.4f, 1.0f);
	//field.scale = DirectX::XMFLOAT3(16.0f, 20.0f, 70.0f);

	//　テストボール
	//ball.Initialize();
	//ball.SetPrimitive(new GeometricSphere2(FRAMEWORK.getDevice()));
	//ball.color = DirectX::XMFLOAT4(0.4f, 0.5f, 0.4f, 1.0f);
	//ball.scale = DirectX::XMFLOAT3(2.0f, 2.0f, 2.0f);
	//ball.pos = { 0.0f, 0.5f, 0.0f };

	stage.Initialize();

	//	「プレイヤー」を初期化
	//player.Initialize( "./Data/tank.fbx" );
	player.Initialize();


	//	敵を生成
	//enemyManager.Initialize();
	//const char*			tank  = "./Data/tank.fbx";
	//float				angle = DirectX::XMConvertToRadians(180.0f);
	//DirectX::XMFLOAT4	color = DirectX::XMFLOAT4(1.0f, .0f, .0f, 1.0f);
	//enemyManager.Set(tank, DirectX::XMFLOAT3(-5.0f, .0f, +5.0f), angle, color);
	//enemyManager.Set(tank, DirectX::XMFLOAT3(  .0f, .0f, +5.0f), angle, color);
	//enemyManager.Set(tank, DirectX::XMFLOAT3(+5.0f, .0f, +5.0f), angle, color);

	//	弾丸管理を初期化

}



void	Game::Release()
{
	//field.Release();			//	「地面」の解放処理
	player.Release();			//	「プレイヤー」の解放処理
	//enemyManager.Release();		//	敵管理」の解放処理

	//endLine.Release();

	//ball.Release();

	stage.Release();
}




bool	Game::Update()
{

	player.Update();					//	「プレイヤー」の更新処理
	//enemyManager.Update();			//	「敵管理」の更新処理
	camera.Update();
	stage.Update();


	//if (GetAsyncKeyState(' ') & 1)
	//{
	//	pWaveManager->WaveProceed();
	//}

	//pWaveManager->EnemyTimer++;
	//if (pWaveManager->EnemyTimer > pWaveManager->intervalTimer)
	//{
	//	pWaveManager->WaveProceed();
	//	pWaveManager->intervalTimer -= 0.5;
	//	pWaveManager->EnemyTimer = 0;
	//}

	//enemyManager.ExistFlg();

	/*******************************************************************************
		パーティクル管理を更新
	*******************************************************************************/
	pParticleManager->Update();


	////	敵と弾丸との衝突判定
	//for (int sn = 0; sn < ShotManager::MAX; sn++)
	//{
	//	Shot* s = shotManager.Get(sn);
	//	if (!s || !s->exist)	continue;

	//	for (int en = 0; en < EnemyManager::MAX; en++)
	//	{
	//		Enemy* e = enemyManager.Get(en);
	//		if (!e || !e->exist)	continue;

	//		if (HitSphere(s->pos, 0.2f, e->pos, e->obj.scale.x))
	//		{
	//			s->obj.Release();
	//			s->exist = false;
	//			e->obj.Release();
	//			e->exist = false;

	//			score += 100;
	//			/*******************************************************************************
	//				パーティクルを用いた破壊演出の作成
	//			*******************************************************************************/
	//			DirectX::XMFLOAT3	pos = s->pos;
	//			pos.x += e->pos.x;		pos.x /= 2.0f;
	//			pos.y += e->pos.y;		pos.y /= 2.0f;
	//			pos.z += e->pos.z;		pos.z /= 2.0f;
	//			for (int n = 0; n < 10; n++)
	//			{
	//				DirectX::XMFLOAT3	vec, power;
	//				const float scale = 0.15f;
	//				const DirectX::XMFLOAT4 color(0.8f, 0.4f, 0.2f, 0.5f);

	//				vec.x = ((rand() % 2001) - 1000) * 0.001f * 0.03f;
	//				vec.y = ((rand() % 2001) - 1000) * 0.001f * 0.03f;
	//				vec.z = ((rand() % 2001) - 1000) * 0.001f * 0.03f;

	//				power.x = 0.0f;
	//				power.z = 0.0f;
	//				power.y = -0.001f;

	//				pParticleManager->Set(pos, vec, power, scale, color, 30);
	//			}
	//		}
	//	}
	//}

	//ball.pos.z += 0.2;

	return	true;
}


void	Game::Render()
{
	blender::Set(blender::ALPHA);

	//	ビュー変換行列
	view = camera.GetViewMatrix();

	//field.Render(view, projection, light_direction);			//	「地面」の描画処理
	player.Render(view, projection, light_direction);			//	「プレイヤー」の描画処理
	//enemyManager.Render(view, projection, light_direction);	//	「敵管理」の描画処理

	//endLine.Render(view, projection, light_direction);

	//ball.Render(view, projection, light_direction);

	stage.Render(view, projection, light_direction);

	/*******************************************************************************
		パーティクル管理を描画
	*******************************************************************************/
	pParticleManager->Render(view, projection);

	// SCORE表示 ///////////////////////////////////
	sprintf_s(SCORE, "SCORE:%d", score);

	sprintf_s(str, "SPACE : shot");

	sprintf_s(D, "D");
	sprintf_s(F, "F");
	sprintf_s(J, "J");
	sprintf_s(K, "K");

	////////////////////////////////////////////////
}