#include	"player.h"

#include	"particle.h"
#include    "stage.h"
#include    "collision.h"
#include    "scene_manager.h"
#include    "select.h"

extern MyMesh blocks[MAP_HEIGHT][MAP_WIDTH];
extern int map0[MAP_HEIGHT][MAP_WIDTH];
/*******************************************************************************
    �u�v���C���[�v�N���X�̏�����
*******************************************************************************/

void	Player::Initialize()
{
    obj.Initialize();
    obj.SetPrimitive(new GeometricCube(pFramework.getDevice()));
    obj.color = DirectX::XMFLOAT4(1.0f, 1.0f, 0.5f, 1.0f);
    obj.scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
    //obj.Load(filename);
    pos = { -7, 5, 0 };
    speed = 0.07f;
    resetFlg = true;
    gravity = -1;
	clearFlg = false;
}
//void	Player::Initialize(const char* filename)
//{
//	obj.Initialize();
//	obj.Load( filename );
//	pos = { -7, 5, 0 };
//	speed = 0.06f;
//}



/*******************************************************************************
    �u�v���C���[�v�N���X�̉��
*******************************************************************************/
void	Player::Release()
{
    obj.Release();
}


/*******************************************************************************
    �u�v���C���[�v�N���X�̕`��
*******************************************************************************/
void	Player::Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir)
{
    obj.pos = this->pos;
    obj.angle.y = this->angle;

    obj.Render(view, projection, light_dir);
}

/*******************************************************************************
    �u�v���C���[�v�N���X�̍X�V
*******************************************************************************/
void	Player::Update()
{
	Move();
	Jump();

	if (resetFlg)
	{
		obj.scale = { 1.0f, 1.0f, 1.0f };
		switch (p_Select.getInstance().map_num)
		{
		case 1:
			pos = { -7, 0, -1 };
			break;

		case 2:
			pos = { -7, 0, -1 };
			break;

		case 3:
			pos = { -5, 0, -1 };
			break;
		}
		resetFlg = false;
	}

	for (int height = 0; height < MAP_HEIGHT; height++)
	{
		for (int width = 0; width < MAP_WIDTH; width++)
		{
			if (HitWall(pos, blocks[height][width].pos))
			{
				switch (map0[height][width])
				{
				case NONE:
					break;

				case BLOCK:
					speed *= -1;
					break;

				case RED_BLOCK:
					speed *= -1;
					break;

				case TRANSPARENT_RED_BLOCK:
					break;

				case BLUE_BLOCK:
					speed *= -1;
					break;

				case TRANSPARENT_BLUE_BLOCK:
					break;

				case SPINE:
					break;

				case RED_SPINE:
					break;

				case TRANSPARENT_RED_SPINE:
					break;

				case BLUE_SPINE:
					break;

				case TRANSPARENT_BLUE_SPINE:
					break;

				case RIGHT_BELT_CONVEYOR:
					speed *= -1;
					break;

				case LEFT_BELT_CONVEYOR:
					speed *= -1;
					break;

				case CLEAR:
					speed *= -1;
					break;
				}
			}

			if (HitCube(pos, blocks[height][width].pos) > 0)
			{
				switch (map0[height][width])
				{
				case NONE:
					break;

				case BLOCK:
					if (GetAsyncKeyState(' ') & 1)
					{
						if (jumpFlg == false)
						{
							pSceneManager.playReturn = true;

							//accele = 0.3f;
							gravity *= -1;
							jumpFlg = true;
						}
					}
					accele = 0;
					pos.x += speed;
					pos.y = pre_pos.y;
					jumpFlg = false;
					break;

				case RED_BLOCK:
					if (GetAsyncKeyState(' ') & 1)
					{
						pSceneManager.playReturn = true;

						if (jumpFlg == false)
						{
							//accele = 0.3f;
							gravity *= -1;
							jumpFlg = true;
						}
						for (int change_height = 0; change_height < MAP_HEIGHT; change_height++)
						{
							for (int change_width = 0; change_width < MAP_WIDTH; change_width++)
							{
								if (map0[change_height][change_width] == RED_BLOCK)
								{
									map0[change_height][change_width] = TRANSPARENT_RED_BLOCK;
								}
								else if (map0[change_height][change_width] == TRANSPARENT_RED_BLOCK)
								{
									map0[change_height][change_width] = RED_BLOCK;
								}

								if (map0[change_height][change_width] == RED_SPINE)
								{
									map0[change_height][change_width] = TRANSPARENT_RED_SPINE;
								}
								else if (map0[change_height][change_width] == TRANSPARENT_RED_SPINE)
								{
									map0[change_height][change_width] = RED_SPINE;
								}
							}
						}
					}
					accele = 0;
					pos.x += speed;
					pos.y = pre_pos.y;
					jumpFlg = false;
					break;

				case TRANSPARENT_RED_BLOCK:
					break;

				case BLUE_BLOCK:
					if (GetAsyncKeyState(' ') & 1)
					{
						if (jumpFlg == false)
						{
							pSceneManager.playReturn = true;

							//accele = 0.3f;
							gravity *= -1;
							jumpFlg = true;
						}
						for (int change_height = 0; change_height < MAP_HEIGHT; change_height++)
						{
							for (int change_width = 0; change_width < MAP_WIDTH; change_width++)
							{
								if (map0[change_height][change_width] == BLUE_BLOCK)
								{
									map0[change_height][change_width] = TRANSPARENT_BLUE_BLOCK;
								}
								else if (map0[change_height][change_width] == TRANSPARENT_BLUE_BLOCK)
								{
									map0[change_height][change_width] = BLUE_BLOCK;
								}
								if (map0[change_height][change_width] == BLUE_SPINE)
								{
									map0[change_height][change_width] = TRANSPARENT_BLUE_SPINE;
								}
								else if (map0[change_height][change_width] == TRANSPARENT_BLUE_SPINE)
								{
									map0[change_height][change_width] = BLUE_SPINE;
								}
							}
						}
					}
					accele = 0;
					pos.x += speed;
					pos.y = pre_pos.y;
					jumpFlg = false;
					break;

				case TRANSPARENT_BLUE_BLOCK:
					break;

				case SPINE:
					// ���S�t���Otrue
					deathFlg = true;
					break;

				case RED_SPINE:
					// ���S�t���Otrue
					deathFlg = true;
					break;

				case TRANSPARENT_RED_SPINE:
					break;

				case BLUE_SPINE:
					// ���S�t���Otrue
					deathFlg = true;
					break;

				case TRANSPARENT_BLUE_SPINE:
					break;

				case RIGHT_BELT_CONVEYOR:
					if (speed < 0)
					{
						speed *= -1;
					}
					break;

				case LEFT_BELT_CONVEYOR:
					if (speed > 0)
					{
						speed *= -1;
					}
					break;

				case CLEAR:
					// �N���A�t���Otrue
					clearFlg = true;
					break;
				}
			}
		}
	}

	if (clearFlg)
	{
		pSceneManager.setChangeScene(state_clear);
	}

	if (deathFlg)
	{
		pSceneManager.playDeath = true;

		pos.x = pre_pos.x;
		pos.y = pre_pos.y;

		obj.scale.x -= 0.05f;
		obj.scale.y -= 0.05f;		
		obj.scale.z -= 0.05f;

		obj.color.w -= 0.05;


		for (int n = 0; n < 10; n++)
		{
			DirectX::XMFLOAT3	vec, power;
			const float scale = 0.15f;
			const DirectX::XMFLOAT4 color(1.0f, .0f, 1.0f, 0.5f);

			vec.x = ((rand() % 2001) - 1000) * 0.001f * 0.03f;
			vec.y = ((rand() % 2001) - 1000) * 0.001f * 0.03f;
			vec.z = ((rand() % 2001) - 1000) * 0.001f * 0.03f;

			power.x = 0.0f;
			power.y = 0.0f;
			power.z = 0.0f;

			pParticleManager->Set(pos, vec, power, scale, color, 30);
		}

		if (obj.scale.x < 0)
		{
			delayTimer++;
			if (delayTimer > 60)
			{
				resetFlg = true;
				deathFlg = false;
				obj.scale = { 0, 0, 0 };
				obj.color.w = 1.0f;
				delayTimer = 0;
			}
		}
	}

	pre_pos.x = pos.x;
	pre_pos.y = pos.y;
}

/*******************************************************************************
    �u�v���C���[�v�N���X�̈ړ�
*******************************************************************************/
void	Player::Move()
{
    accele += 0.1f;
    //Vertical_movement = (pos.y + (accele * gravity));
    Vertical_movement = accele * gravity;

    if (Vertical_movement > 0.3f)
    {
        Vertical_movement = 0.3f;
    }
    if (Vertical_movement < -0.3f)
    {
        Vertical_movement = -0.3f;
    }

    //pre_pos.y = pos.y;
    pos.y += Vertical_movement;

    //�@�v���C���[�̈ړ�
    if (GetAsyncKeyState(VK_LEFT))
    {
        pos.x -= 0.1f;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        pos.x += 0.1f;
    }

    if (GetAsyncKeyState(VK_UP))
    {
        pos.z += 0.1f;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        pos.z -= 0.1f;
    }

    if (GetAsyncKeyState('W'))
    {
        pos.y += 0.1f;
    }
    if (GetAsyncKeyState('S'))
    {
        pos.y -= 0.1f;
    }
}

void Player::Jump()
{
    //accele += 0.01f;
}

#pragma region Store

//const float dangle	= DirectX::XMConvertToRadians( 1.0f );		//	1�x
//const float speed	= 0.05f;									//	�v���C���[�̑��x

//	��]
//if (GetAsyncKeyState(VK_LEFT)  < 0)	angle -= dangle;
//if (GetAsyncKeyState(VK_RIGHT) < 0)	angle += dangle;

//if (GetAsyncKeyState(VK_UP) < 0)
//{
//	float dx = sinf(angle);			//	�ړ��x�N�g��(X����)
//	float dz = cosf(angle);			//	�ړ��x�N�g��(Z����)
//	pos.x += dx * speed;
//	pos.z += dz * speed;
//}

////	�e�۔��ˏ���
//if (GetAsyncKeyState(' ') & 1)
//{
//	const float	SHOT_SPEED = 0.5f;
//	const float OFS_FRONT = 0.45f;
//	const float OFS_HEIGHT = 0.55f;

//	DirectX::XMFLOAT3 p = pos;
//	p.x += sinf(angle) * OFS_FRONT;
//	p.z += cosf(angle) * OFS_FRONT;
//	p.y += OFS_HEIGHT;
//	shotManager.Set(p, angle, SHOT_SPEED, 0.2f);

//	//	�p�[�e�B�N���Ǘ��N���X�̐ݒu�֐��̌Ăяo��(�����p)
//	//pParticleManager->Set(p, 1.0f, DirectX::XMFLOAT4(0.8f, 0.4f, 0.2f, 0.6f));

//	/*******************************************************************************
//		�p�[�e�B�N����p�������o(�C���̍ۂɔ�������ΉԂ��ۂ���)
//	*******************************************************************************/
//	for (int n = 0; n < 5; n++)
//	{
//		DirectX::XMFLOAT3	vec, power;
//		static const float	MUZZLE_SPEED = SHOT_SPEED*0.4f;
//		static const float SCALE = 0.05f;
//		static const DirectX::XMFLOAT4 COLOR(0.8f, 0.4f, 0.2f, 0.5f);

//		vec.x = ((rand() % 2001) - 1000) * 0.00002f + sinf(angle)*MUZZLE_SPEED;
//		vec.z = ((rand() % 2001) - 1000) * 0.00002f + cosf(angle)*MUZZLE_SPEED;
//		vec.y = ((rand() % 2001) - 1000) * 0.00002f;

//		power.x = 0.0f;
//		power.z = 0.0f;
//		power.y = -0.002f;

//		pParticleManager->Set(p, vec, power, SCALE, COLOR, 5);
//	}

//}
#pragma endregion
