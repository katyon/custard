#pragma once

#include	<directxmath.h>
#include	"my_mesh.h"


/*******************************************************************************
TODO:01 WAVE�t���O���ݓG�ݒ�\���̂��`����
����    �P�Ȃ�G�o�����ł͂Ȃ��AWAVE�̉��Ԗڂɏo�����邩�̏�����������
--------------------------------------------------------------------------------
�菇    �ȉ��̃����o�����\���̂��`����
		�Eint		�ԍ�(��WAVE�ڂɏo�����邩�̊Ǘ��ԍ�)
		�Eint		���f���ԍ�(�ǂ̃��f�����g�p���邩�̊Ǘ��ԍ�)
		�Efloat		���W(X,Z�̂݁A�����Y�l���ꗥ0�Ƃ��ĊǗ�����\��)
		�Efloat		��]�p�x
		�EXMFLOAT4	�F(3�F+�s�����x)
*******************************************************************************/
class Wave
{
public:
	int wave_num;
	int model_num;
	float pos_x;
	float pos_z;
	float angle;
	DirectX::XMFLOAT4 color = { 0.8f, 0.4f, 0.2f, 0.5f };

	////////////////
	int existFlg = 180;
};

/*******************************************************************************
TODO:02 WAVE�Ǘ��N���X���`����
����    �G�o��(WAVE)�Ǘ��N���X���쐬����
		�G�o���f�[�^�����łȂ��A1�X�e�[�W���Ŏg�p����G���f��(�̃I���W�i��)��
		�S�Ă��̃N���X���Ǘ�����`�Ő݌v����
--------------------------------------------------------------------------------
�菇    �ȉ��̃����o�A���\�b�h�����\���̂��`����
		�Econst int		���f���ő吔(�I���W�i�����f���̍ő吔�A�����l:10)
		�EMyMesh		�I���W�i�����f���z��(�v�f���F���f���ő吔)
		�E�G�ݒ�\����*	�G�o���f�[�^(�|�C���^�̂�)
		�Eint			�J�E���^(�o���f�[�^�̉����܂ŏo�����Ă��邩���L�^����ׂ̕ϐ�)
		�Eint			��WAVE�ԍ�(��WAVE�܂œG���o�Ă��邩���Ǘ�)

		�Evoid	�������֐�(������z��, �G�ݒ�\���̔z��)
		�Evoid	����֐�()
		�Ebool	�����֐�()
		�Evoid	WAVE�i�s�֐�()	{ ��WAVE�ԍ���1���₷; }
		
	���K�v�ɉ����ăV���O���g�����A���̑������o�̒ǉ������Ȃ���
*******************************************************************************/
class WaveManager
{
public:
	static const int model_max = 100;
	int EnemyTimer = 0;
	float intervalTimer;
	int ThisWave;
private:
	MyMesh myModel[model_max];
	Wave* EnemyData;
	int count;

public:
	void init(char** filename, Wave* ed);
	void release();
	bool create();

	/////////////
	/////////////

	void WaveProceed()
	{
		if (EnemyData[count].wave_num < 0) return;
		ThisWave++;
		//if (EnemyData[count].wave_num > 10)
		//{
		//	EnemyData[count].wave_num = 0;
		//}
	}

	static WaveManager* getInstance()
	{
		static WaveManager instance;
		return &instance;
	}
};

#define pWaveManager WaveManager::getInstance()



































