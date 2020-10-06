#pragma once

#include	<DirectXMath.h>

#include	"my_mesh.h"



/*******************************************************************************
	�u�v���C���[�v�N���X
*******************************************************************************/
class Player
{
public:
	MyMesh				obj;				//	�u���f���I�u�W�F�N�g�v
	DirectX::XMFLOAT3	pos;				//	�u�ʒu(���W)�v
	float				angle;				//	�u��]�p�x�v

	bool                jumpFlg = false;
	float               accele = 0.1f;
	int                 gravity = 1;

	void    Jump();

	void	Initialize( const char* );																							//	�������֐�
	void	Release();																											//	����֐�
	void	Move();																												//	�ړ��֐�
	void	Render( const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir );	//	�`��֐�
};