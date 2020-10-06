#pragma once

#include	<DirectXMath.h>

#include	"my_mesh.h"

/*******************************************************************************
	�u�G�v�N���X
*******************************************************************************/
class Stage
{
public:
	MyMesh				obj;		//	�u���f���I�u�W�F�N�g�v
	DirectX::XMFLOAT3	pos;		//	�u�ʒu(���W)�v
	float				angle;		//	�u��]�p�x�v

	DirectX::XMFLOAT4	color;		//	�u�F�v
	bool				exist;		//	�u���݃t���O�v


	//	�G�N���X�ɏ���ǉ�
	int					state;		//	�u��ԁv
	int					timer;		//	�u�^�C�}�[�v

	void	Initialize(const char*);																							//	�������֐�

	void	Release();																											//	����֐�
	void	Move();																												//	�ړ��֐�
	void	Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir); 	//	�`��֐�
	
};


/*******************************************************************************
	�u�G�Ǘ��v�N���X
*******************************************************************************/
class EnemyManager
{
public:
	static const int	MAX = 32;				//	�u�ő吔�v	

private:
	Enemy				data[MAX];				//	�u�G�f�[�^�v


public:
	void	Initialize();																										//	�������֐�
	void	Release();																											//	����֐�
	void	Update();																											//	�X�V�֐�
	void	Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir);	//	�`��֐�

	Enemy* Set(const char* filename, DirectX::XMFLOAT3 pos, float angle, DirectX::XMFLOAT4 color);								//	�G�ݒ�֐�
	Enemy* EnemyManager::Set(MyMesh& mesh, DirectX::XMFLOAT3 pos, float angle, DirectX::XMFLOAT4 color);

	Enemy* Get(int no) {
		if ((unsigned int)no >= MAX)	return	nullptr;
		return		&data[no];
	}

};

extern	EnemyManager	enemyManager;		//	��������ǉ�
