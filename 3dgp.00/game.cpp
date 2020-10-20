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
	�O���[�o���ϐ�
*******************************************************************************/
//MyMesh			field;				//	�n�ʗp�ϐ��u�n�ʁv
Player			player;				//	�v���C���[�p�ϐ��u�v���C���[�v
Camera			camera;				//	�J�����p�ϐ��u�J�����v

Stage           stage;

//MyMesh          endLine;

//MyMesh          ball;

Text            text;

/*******************************************************************************
TODO:07 WAVE�Ǘ��N���X�̌Ăяo��
����    Game�N���X�̊e����WAVE�Ǘ��N���X�̃��\�b�h���Ăяo��
--------------------------------------------------------------------------------
�菇    Game�N���X�̊e���ňȉ��̏��������s����
		�EGame::Initialize�֐���WAVE�Ǘ��N���X�̏������֐����Ăяo��
		�@���̎��A������TODO_06�Œǉ������f�[�^�Ƃ���
		�EGame::Initialize�֐��ňȑO���炠�����G�o���������R�����g������
		�@(�G�o����WAVE�Ǘ��N���X�Ɉꌳ������ׁA�s�v�ƂȂ�)
		�EGame::Update�֐���WAVE�Ǘ��N���X�̐����֐����Ăяo��
		�@���̎��A�G�̍X�V�����O�ɍs�����������肷��
		�EGame::Update�֐���(�g���Ă��Ȃ�)�����̃L�[������������
		�@WAVE�Ǘ��N���X��WAVE�i�s�֐����Ăяo��
�m�F	�N�����ɓG��3�̏o�����A�ݒ肵���L�[�������x�ɓG��2�́�3�̂Əo�������OK
*******************************************************************************/

/*******************************************************************************
TODO:09 WAVE�S�Ō��m�ɔ��������Ăяo��
����    �G�̌�WAVE�S�ł��m�F������A����WAVE���Ăяo���悤�ɍ쐬����
--------------------------------------------------------------------------------
�菇    Game::Update�֐����ŁA�G�̑S�ł����m������WAVE��
		�i�s�����悤�ɕύX����
		���̍ہATODO_07�ōs���Ă����u�L�[��������WAVE�i�s�v��
		�폜���Ă�����
�m�F	�G��S�ł����閈�Ɏ���WAVE���i�s����A�ŏIWAVE��S�ł����Ă�
		���ɖ�肪�������OK
*******************************************************************************/


void	Game::Initialize()
{

	score = 0;

	srand((unsigned)time(NULL));

	//	���e�ϊ��s��
	projection = camera.GetProjectionMatrix();

	//	����(���s��)
	light_direction = DirectX::XMFLOAT4(0, -1, 1, 0);		//	��+�� ���� ��+�O�ւ̃��C�g


	//	�u�n�ʁv��������
	//field.Initialize();
	//field.SetPrimitive( new GeometricRect( FRAMEWORK.getDevice() ) );
	//field.color = DirectX::XMFLOAT4(0.5f, 1.0f, 0.4f, 1.0f);
	//field.scale = DirectX::XMFLOAT3(16.0f, 20.0f, 70.0f);

	//�@����\��  /////////////////////////////////////////////////
	//endLine.Initialize();
	//endLine.SetPrimitive(new GeometricRect(FRAMEWORK.getDevice()));
	//endLine.color = DirectX::XMFLOAT4(1.0f, 0.5f, 0.4f, 1.0f);
	//endLine.scale = DirectX::XMFLOAT3(16.0f, 20.0f, 2.0f);
	//endLine.pos = { 0.0f, 0.1f, -5.0f };
	//////////////////////////////////////////////////////////////

	//	�u�n�ʁv��������
	//field.Initialize();
	//field.SetPrimitive(new GeometricRect(FRAMEWORK.getDevice()));
	//field.color = DirectX::XMFLOAT4(0.5f, 1.0f, 0.4f, 1.0f);
	//field.scale = DirectX::XMFLOAT3(16.0f, 20.0f, 70.0f);

	//�@�e�X�g�{�[��
	//ball.Initialize();
	//ball.SetPrimitive(new GeometricSphere2(FRAMEWORK.getDevice()));
	//ball.color = DirectX::XMFLOAT4(0.4f, 0.5f, 0.4f, 1.0f);
	//ball.scale = DirectX::XMFLOAT3(2.0f, 2.0f, 2.0f);
	//ball.pos = { 0.0f, 0.5f, 0.0f };

	stage.Initialize();

	//	�u�v���C���[�v��������
	//player.Initialize( "./Data/tank.fbx" );
	player.Initialize();


	//	�G�𐶐�
	//enemyManager.Initialize();
	//const char*			tank  = "./Data/tank.fbx";
	//float				angle = DirectX::XMConvertToRadians(180.0f);
	//DirectX::XMFLOAT4	color = DirectX::XMFLOAT4(1.0f, .0f, .0f, 1.0f);
	//enemyManager.Set(tank, DirectX::XMFLOAT3(-5.0f, .0f, +5.0f), angle, color);
	//enemyManager.Set(tank, DirectX::XMFLOAT3(  .0f, .0f, +5.0f), angle, color);
	//enemyManager.Set(tank, DirectX::XMFLOAT3(+5.0f, .0f, +5.0f), angle, color);

	//	�e�ۊǗ���������

}



void	Game::Release()
{
	//field.Release();			//	�u�n�ʁv�̉������
	player.Release();			//	�u�v���C���[�v�̉������
	//enemyManager.Release();		//	�G�Ǘ��v�̉������

	//endLine.Release();

	//ball.Release();

	stage.Release();
}




bool	Game::Update()
{

	player.Update();					//	�u�v���C���[�v�̍X�V����
	//enemyManager.Update();			//	�u�G�Ǘ��v�̍X�V����
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
		�p�[�e�B�N���Ǘ����X�V
	*******************************************************************************/
	pParticleManager->Update();


	////	�G�ƒe�ۂƂ̏Փ˔���
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
	//				�p�[�e�B�N����p�����j�󉉏o�̍쐬
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

	//	�r���[�ϊ��s��
	view = camera.GetViewMatrix();

	//field.Render(view, projection, light_direction);			//	�u�n�ʁv�̕`�揈��
	player.Render(view, projection, light_direction);			//	�u�v���C���[�v�̕`�揈��
	//enemyManager.Render(view, projection, light_direction);	//	�u�G�Ǘ��v�̕`�揈��

	//endLine.Render(view, projection, light_direction);

	//ball.Render(view, projection, light_direction);

	stage.Render(view, projection, light_direction);

	/*******************************************************************************
		�p�[�e�B�N���Ǘ���`��
	*******************************************************************************/
	pParticleManager->Render(view, projection);

	// SCORE�\�� ///////////////////////////////////
	sprintf_s(SCORE, "SCORE:%d", score);

	sprintf_s(str, "SPACE : shot");

	sprintf_s(D, "D");
	sprintf_s(F, "F");
	sprintf_s(J, "J");
	sprintf_s(K, "K");

	////////////////////////////////////////////////
}