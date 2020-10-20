#include "stage.h"

#include "my_mesh.h"
#include "framework.h"
#include "player.h"
#include "collision.h"

/*******************************************************************************
	グローバル変数
*******************************************************************************/
MyMesh blocks[MAP_HEIGHT][MAP_WIDTH];

extern Player player;

//  マップ定義  //////////////////////////////////
// STAGE 0 
int map1[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

//STAGE 1
int map0[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 1, 1, 1, 1, 0, 9, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 1, 1, 3, 3, 1, 1, 3, 3, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 3, 3, 3, 3, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 1, 5, 5, 5, 5, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 7, 0, 0, 1, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 8, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 8, 0, 8, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0,13, 0, 0, 5, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 0, 0, 0, 7, 0, 0, 0, 8, 0, 8, 0, 8, 0, 8, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
};

// STAGE 2
int map2[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 6, 1, 9, 9, 9, 9, 0, 0, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 4, 4, 1 },
	{ 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 9, 9, 9, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,10, 8,10, 8, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 8,10, 8,10, 0, 0, 0, 0, 0, 1 },
	{ 1, 7, 7, 7, 7, 7, 7, 5, 0, 0, 0, 0, 0, 0, 0, 1, 1,10,10,10,10,10,10, 0, 0,13, 0, 0, 0, 8,10, 8,10, 8, 1, 1, 1, 3, 3, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

//STAGE 3
int map3[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 1, 0, 0, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1,},
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1, 8, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 1, 1, 1, 1, 1, 6, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 6, 1, 1, 1, 1, 1, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,10, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 8, 8, 0, 0, 0, 4, 4, 2, 2, 2, 2, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1,13, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 8, 8, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 1,},
};


/////////////////////////////////////////////////

void Stage::CreateBlock()
{
	for (int height = 0; height < MAP_HEIGHT; height++)
	{
		for (int width = 0; width < MAP_WIDTH; width++)
		{
			switch (map0[height][width])
			{
			case NONE:
				break;

			case BLOCK:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricCube(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case RED_BLOCK:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricCube(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(1.0f, 0.2f, 0.2f, 1.0f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case TRANSPARENT_RED_BLOCK:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricCube(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(1.0f, 0.2f, 0.2f, 0.2f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case BLUE_BLOCK:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricCube(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(0.2f, 0.2f, 1.0f, 1.0f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case TRANSPARENT_BLUE_BLOCK:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricCube(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(0.2f, 0.2f, 1.0f, 0.2f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;


			case SPINE:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricSphere2(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(.0f, .0f, .0f, 1.0f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case RED_SPINE:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricSphere2(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(1.0f, 0.2f, 0.2f, 1.0f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case TRANSPARENT_RED_SPINE:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricSphere2(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(1.0f, 0.2f, 0.2f, 0.2f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case BLUE_SPINE:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricSphere2(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(0.2f, 0.2f, 1.0f, 1.0f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case TRANSPARENT_BLUE_SPINE:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricSphere2(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(0.2f, 0.2f, 1.0f, 0.2f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case RIGHT_BELT_CONVEYOR:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricCube(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(0.1f, 1.0f, 0.1f, 1.0f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case LEFT_BELT_CONVEYOR:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricCube(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(0.4f, 1.0f, 0.4f, 1.0f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;

			case CLEAR:
				blocks[height][width].Initialize();
				blocks[height][width].SetPrimitive(new GeometricSphere(pFramework.getDevice()));
				blocks[height][width].color = DirectX::XMFLOAT4(0.4f, 1.0f, 0.4f, 1.0f);
				blocks[height][width].scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
				blocks[height][width].pos = DirectX::XMFLOAT3(width - 10, -height + 12, 1.0f);
				break;
			}
		}
	}
}

void Stage::Initialize()
{
	CreateBlock();
}

void Stage::Release()
{
	for (int height = 0; height < MAP_HEIGHT; height++)
	{
		for (int width = 0; width < MAP_WIDTH; width++)
		{
			blocks[height][width].Release();
		}
	}
}

void Stage::Update()
{
	for (int height = 0; height < MAP_HEIGHT; height++)
	{
		for (int width = 0; width < MAP_WIDTH; width++)
		{
			if (HitCube(player.pos, blocks[height][width].pos))
			{

			}
		}
	}
}

void Stage::Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir)
{
	for (int height = 0; height < MAP_HEIGHT; height++)
	{
		for (int width = 0; width < MAP_WIDTH; width++)
		{
			if (map0[height][width] == RED_BLOCK)
			{
				blocks[height][width].color = DirectX::XMFLOAT4(1.0f, 0.2f, 0.2f, 1.0f);
			}
			if (map0[height][width] == TRANSPARENT_RED_BLOCK)
			{
				blocks[height][width].color = DirectX::XMFLOAT4(1.0f, 0.2f, 0.2f, 0.2f);
			}

			if (map0[height][width] == BLUE_BLOCK)
			{
				blocks[height][width].color = DirectX::XMFLOAT4(0.2f, 0.2f, 1.0f, 1.0f);
			}
			if (map0[height][width] == TRANSPARENT_BLUE_BLOCK)
			{
				blocks[height][width].color = DirectX::XMFLOAT4(0.2f, 0.2f, 1.0f, 0.2f);
			}

			if (map0[height][width] == RED_SPINE)
			{
				blocks[height][width].color = DirectX::XMFLOAT4(1.0f, 0.2f, 0.2f, 1.0f);
			}
			if (map0[height][width] == TRANSPARENT_RED_SPINE)
			{
				blocks[height][width].color = DirectX::XMFLOAT4(1.0f, 0.2f, 0.2f, 0.2f);
			}

			if (map0[height][width] == BLUE_SPINE)
			{
				blocks[height][width].color = DirectX::XMFLOAT4(0.2f, 0.2f, 1.0f, 1.0f);
			}
			if (map0[height][width] == TRANSPARENT_BLUE_SPINE)
			{
				blocks[height][width].color = DirectX::XMFLOAT4(0.2f, 0.2f, 1.0f, 0.2f);
			}

			blocks[height][width].Render(view, projection, light_dir);
		}
	}
}