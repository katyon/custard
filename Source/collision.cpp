#include	"collision.h"
#include    "player.h"
#include    <vector>
#include    <stdio.h>


extern Player player;

enum HitPATTERN
{
	HIT_UP = 1,
	HIT_DOWN,
	HIT_LEFT,
	HIT_RIGHT
};

/*******************************************************************************
	球同士の判定関数
*******************************************************************************/
bool HitSphere(const DirectX::XMFLOAT3& p1, float r1, const DirectX::XMFLOAT3& p2, float r2)
{
	//	半径の合算の2乗
	const float R2 = (r1 + r2) * (r1 + r2);

	//	中心同士の距離の2乗
	DirectX::XMFLOAT3 vec;
	vec.x = p1.x - p2.x;
	vec.y = p1.y - p2.y;
	vec.z = p1.z - p2.z;
	float L2 = vec.x*vec.x + vec.y*vec.y + vec.z*vec.z;

	//	衝突判定
	if (L2 < R2)	return	true;

	return	false;
}

int HitCube(const DirectX::XMFLOAT3& a, const DirectX::XMFLOAT3& b)
{
	DirectX::XMFLOAT2 A = { a.x - 0.5f, a.y - 0.5f };
	DirectX::XMFLOAT2 REL_A = { a.x + 0.5f, a.y + 0.5f };
	DirectX::XMFLOAT2 B = { b.x - 0.5f, b.y - 0.5f };
	DirectX::XMFLOAT2 REL_B = { b.x + 0.5f, b.y + 0.5f };
	if (A.x <= REL_B.x && 
		B.x <= REL_A.x && 
		A.y <= REL_B.y && 
		B.y <= REL_A.y) return true;
	return false;
}

int HitCube2(const DirectX::XMFLOAT3& a, const DirectX::XMFLOAT3& b)
{
	DirectX::XMFLOAT2 A = { a.x - 0.5f, a.y - 0.5f };
	DirectX::XMFLOAT2 REL_A = { a.x + 0.5f, a.y + 0.5f };
	DirectX::XMFLOAT2 B = { b.x - 0.5f, b.y - 0.5f };
	DirectX::XMFLOAT2 REL_B = { b.x + 0.5f, b.y + 0.5f };
	if (A.x <= REL_B.x && B.x <= REL_A.x && A.y <= REL_B.y && B.y <= REL_A.y)
	{
		if (B.x < REL_A.x && a.x < b.x)
		{
			return HIT_LEFT;
		}

		if (A.x < REL_B.x && a.x > b.x)
		{
			return HIT_RIGHT;
		}
		if (A.y <= REL_B.y && a.y < b.y)
		{
			return HIT_UP;
		}
		if (B.y <= REL_A.y && a.y > b.y)
		{
			return HIT_DOWN;
		}
	}
	return 0;
}

bool HitWall(const DirectX::XMFLOAT3& a, const DirectX::XMFLOAT3& b)
{
	DirectX::XMFLOAT2 A0 = { a.x - 0.5f, a.y + 0.05f }; //上
	DirectX::XMFLOAT2 A1 = { a.x + 0.5f, a.y + 0.01f };

	DirectX::XMFLOAT2 A2 = { a.x - 0.5f, a.y - 0.01f }; //下
	DirectX::XMFLOAT2 A3 = { a.x + 0.5f, a.y - 0.05f };

	DirectX::XMFLOAT2 B = { b.x - 0.5f, b.y - 0.5f };
	DirectX::XMFLOAT2 REL_B = { b.x + 0.5f, b.y + 0.5f };

	if (A0.x <= REL_B.x && B.x <= A1.x && A0.y <= REL_B.y && B.y <= A1.y) return true;
	if (A2.x <= REL_B.x && B.x <= A3.x && A2.y <= REL_B.y && B.y <= A3.y) return true;

	return false;
}

// 辺を使用した矩形とマップ値の当たり
//bool HitCube2(const DirectX::XMFLOAT3& a, const DirectX::XMFLOAT3& pre_a, const DirectX::XMFLOAT3& b)
//{
//	/*
//	   B0   v1   B1
//		+---------+
//		|		  |
//	  v0|    b    |v2
//		|         |
//		+---------+
//	   B3   v3   B2
//	*/
//
//	// bの頂点定義
//	DirectX::XMFLOAT2 B0 = { b.x - 0.5f, b.y - 0.5f };
//	DirectX::XMFLOAT2 B1 = { b.x + 0.5f, b.y - 0.5f };
//	DirectX::XMFLOAT2 B2 = { b.x + 0.5f, b.y + 0.5f };
//	DirectX::XMFLOAT2 B3 = { b.x - 0.5f, b.y + 0.5f };
//
//	// aの進行ベクトル(今回はPlayer)
//	DirectX::XMFLOAT2 A_Vector = { pre_a.x - a.x, pre_a.y - a.y };
//
//	// bの縁ベクトル(時計回り)
//	DirectX::XMFLOAT2 v0 = { B0.x - B3.x, B0.y - B3.y };
//	DirectX::XMFLOAT2 v1 = { B1.x - B0.x, B1.y - B0.y };
//	DirectX::XMFLOAT2 v2 = { B2.x - B1.x, B2.y - B1.y };
//	DirectX::XMFLOAT2 v3 = { B3.x - B2.x, B3.y - B2.y };
//
//	return 0;
//
//}

//bool HitCube(const DirectX::XMFLOAT3& a, const DirectX::XMFLOAT3& rel_a, const DirectX::XMFLOAT3& b, const DirectX::XMFLOAT3& rel_b)
//{
//	DirectX::XMFLOAT2 A = { a.x - 0.5f, a.y - 0.5f };
//	DirectX::XMFLOAT2 REL_A = { rel_a.x + 0.5f, .y + 0.5f };
//	DirectX::XMFLOAT2 B = { b.x - 0.5f, a.y - 0.5f };
//	DirectX::XMFLOAT2 REL_B = { a.x + 0.5f, a.y + 0.5f };
//	if (a.x <= rel_b.x && b.x <= rel_a.x && a.y <= rel_b.y && b.y <= rel_a.y) return true;
//	return false;
//}
