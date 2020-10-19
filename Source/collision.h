#pragma once

#include	<DirectXMath.h>


/*******************************************************************************
	�Փ˔���p�N���X
*******************************************************************************/

bool HitSphere(const DirectX::XMFLOAT3& p1, float r1, const DirectX::XMFLOAT3& p2, float r2 );

int HitCube(const DirectX::XMFLOAT3& a, const DirectX::XMFLOAT3& b);

int HitCube2(const DirectX::XMFLOAT3& a, const DirectX::XMFLOAT3& b);

bool HitWall(const DirectX::XMFLOAT3& a, const DirectX::XMFLOAT3& b);

