#include	"wave.h"


/*******************************************************************************
TODO:06 WAVE管理用のデータを作成する
説明	オリジナルモデルや敵出現(WAVE管理)データをここで定義する
		このようなデータはSTAGE毎に用意する事となるので、
		膨大なデータを多数作成する事が予想される場合、
		それ単体で.cppを作成すると、ソース管理が容易になる
--------------------------------------------------------------------------------
手順    以下の処理のコメントを外し、適切な形に修正せよF
		また、何をしているのかを確認せよ
		更に、必要に応じてプログラムを各所に追加せよ
*******************************************************************************/
char*	modelNames01[] = 
{
	"Data\\tank.fbx",		//	00:戦車
	NULL					//	終端
};

//WAVEフラグ込み敵設定構造体 
	Wave waveData01[] = 
	{
//	  番号    ﾓﾃﾞﾙ 座標X,Z    角度   色
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

	{ -1,	-1,	0, 0, 0,	DirectX::XMFLOAT4(0,0,0,0) }		//	終端
};
