#pragma once

#include	<DirectXMath.h>


/*******************************************************************************
	�u�J�����v�N���X
*******************************************************************************/
class Camera
{
public:
	/*******************************************************************************
		�J������ԊǗ��ԍ��̐錾
	*******************************************************************************/
	enum MODE
	{
		WATCH,				//	�u�Ď��J�����v
		DIRECTIONAL,		//	�u���Έʒu�Œ�J�����v
		CHASE,				//	�u�ǐՃJ�����v
		TPS,				//	�u3�l�̃J����(TPS)�v
		FPS,				//	�u1�l�̃J����(FPS)�v
		MAX					//	�u�J�����Ǘ��ԍ��ő�l�v	
	};

private:
	/*******************************************************************************
		�J������ԕۑ��p�ϐ��̒�`
	*******************************************************************************/
	int		mode;

public:
	DirectX::XMFLOAT3	pos;				//	�u�ʒu(���W)�v
	DirectX::XMFLOAT3	target;				//	�u�����_�v
	DirectX::XMMATRIX	projection;			//	�u���e�s��v

	Camera();
	/*******************************************************************************
		�J�����X�V�֐��̐錾
	*******************************************************************************/
	void				Update();					//	�X�V�֐�

private:		//	�ǉ������o�֐�(�O������Ăяo���\�肪�����̂�private��)(�����g�ݕ����˂��c)
	void				Watch();		//	�Ď��J�����֐�
	void				Directional();	//	���Έʒu�Œ�J�����֐�
	void				Chase();		//	�ǐՃJ�����֐�
	void				Tps();			//	3�l�̃J����(TPS)�֐�
	void				Fps();			//	1�l�̃J����(FPS)�֐�
public:

	DirectX::XMMATRIX	SetOrthographicMatrix(float w, float h, float znear, float zfar);			//	���s���e�s��ݒ�֐�
	DirectX::XMMATRIX	SetPerspectiveMatrix(float fov, float aspect, float znear, float zfar);	//	�������e�s��ݒ�֐�
	DirectX::XMMATRIX	GetViewMatrix();															//	�r���[�s��擾�֐�
	DirectX::XMMATRIX	GetProjectionMatrix() { return	projection; }								//	���e�s��擾�֐�

};