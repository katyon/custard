#include	"wave.h"


/*******************************************************************************
TODO:06 WAVE�Ǘ��p�̃f�[�^���쐬����
����	�I���W�i�����f����G�o��(WAVE�Ǘ�)�f�[�^�������Œ�`����
		���̂悤�ȃf�[�^��STAGE���ɗp�ӂ��鎖�ƂȂ�̂ŁA
		�c��ȃf�[�^�𑽐��쐬���鎖���\�z�����ꍇ�A
		����P�̂�.cpp���쐬����ƁA�\�[�X�Ǘ����e�ՂɂȂ�
--------------------------------------------------------------------------------
�菇    �ȉ��̏����̃R�����g���O���A�K�؂Ȍ`�ɏC������F
		�܂��A�������Ă���̂����m�F����
		�X�ɁA�K�v�ɉ����ăv���O�������e���ɒǉ�����
*******************************************************************************/
char*	modelNames01[] = 
{
	"Data\\tank.fbx",		//	00:���
	NULL					//	�I�[
};

//WAVE�t���O���ݓG�ݒ�\���� 
	Wave waveData01[] = 
	{
//	  �ԍ�    ���� ���WX,Z    �p�x   �F
	{ 0,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{ 1,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{ 2,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{ 3,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{ 4,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{ 5,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{ 6,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{ 7,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{ 8,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },											
	{ 9,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{10,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,1,0,1.0f) },
	{11,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{12,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{13,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{14,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{15,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{16,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{17,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{18,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{19,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,1,0,1.0f) },
	{20,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{21,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{22,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{23,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{24,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{25,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{26,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{27,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{28,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{29,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,1,0,1.0f) },
	{30,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{31,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{32,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{33,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{34,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{35,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{36,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{37,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{38,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{39,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,1,0,1.0f) },
	{40,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{41,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{42,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{43,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{44,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{45,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{46,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{47,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{48,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{49,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(0.2f,0,7,0.4f) },
	{50,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{51,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{52,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{53,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{54,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{55,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{56,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{57,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{58,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{59,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,1,0,1.0f) },
	{60,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{61,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{62,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{63,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{64,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{65,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{66,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{67,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{68,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{69,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,1,0,1.0f) },
	{70,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{71,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{72,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{73,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{74,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{75,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{76,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{77,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{78,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{79,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,1,0,1.0f) },
	{80,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{81,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{82,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{83,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{84,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{85,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{86,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{87,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{88,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{89,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,1,0,1.0f) },
	{90,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{91,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{92,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{93,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{94,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{95,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{96,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{97,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{98,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(1.0f,0,0,1.0f) },
	{99,	  0,	(rand() % 4) * 4 - 6, +30,	  180,	 DirectX::XMFLOAT4(0.0f,1,0,1.0f) },

	{ -1,	-1,	0, 0, 0,	DirectX::XMFLOAT4(0,0,0,0) }		//	�I�[
};
