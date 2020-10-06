#pragma once

#include <directxmath.h>

#include "static_mesh.h"


class MyMesh
{
private:
	bool				bLoad;

public:
	GeometricPrimitive*	obj;

	DirectX::XMFLOAT3	pos;				//	�u�ʒu�v
	DirectX::XMFLOAT3	angle;				//	�u(��])�p�x�v
	DirectX::XMFLOAT3	scale;				//	�u�傫���v

	DirectX::XMFLOAT4	color;

	void	Initialize();
	bool	Load(const char* fbx_filename);
	void	SetPrimitive(GeometricPrimitive* primitive);
	void	SetMesh(MyMesh& org);
	void	Release();
	void	Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir);

	DirectX::XMMATRIX	GetWorldMatrix();

};