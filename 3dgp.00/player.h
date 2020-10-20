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

	DirectX::XMFLOAT3   pre_pos;			// previous_position

	bool                jumpFlg = true;
	float               accele = 0.3f;
	float				speed = 0.1f;       // �������̈ړ��ϐ�
	int                 gravity = 1;

	bool                skyFlg;
	bool                groundFlg;
	bool                deathFlg = false;
	bool				resetFlg = false;

	bool				clearFlg = false;

	float               Vertical_movement;
	   
	void    Jump();
	void	Move();																												//	�ړ��֐�

	void	Initialize();																										//	�������֐�
	//void	Initialize( const char* );																							//	�������֐�
	void	Release();																											//	����֐�
	void    Update();
	void	Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir);	//	�`��֐�
};