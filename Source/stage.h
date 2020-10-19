#pragma once

#include <DirectXMath.h>

#define MAP_WIDTH  40
#define MAP_HEIGHT 15

enum STAGE
{
    STAGE01,
    STAGE02,
    STAGE03,
    STAGE04
};

enum Block
{
    NONE,
    BLOCK,
    RED_BLOCK,
    TRANSPARENT_RED_BLOCK,
    BLUE_BLOCK,
    TRANSPARENT_BLUE_BLOCK,

    SPINE,
    RED_SPINE,
    TRANSPARENT_RED_SPINE,
    BLUE_SPINE,
    TRANSPARENT_BLUE_SPINE,

    RIGHT_BELT_CONVEYOR,
    LEFT_BELT_CONVEYOR,
    CLEAR
};

//enum Block
//{
//    NONE,
//    WALL,
//    FLOOR,
//    RED_WALL,
//    RED_FLOOR,
//    TRANSPARENT_RED_WALL,
//    TRANSPARENT_RED_FLOOR,
//    BLUE_WALL,
//    BLUE_FLOOR,
//    TRANSPARENT_BLUE_WALL,
//    TRANSPARENT_BLUE_FLOOR,
//
//    SPINE,
//    RED_SPINE,
//    TRANSPARENT_RED_SPINE,
//    BLUE_SPINE,
//    TRANSPARENT_BLUE_SPINE,
//
//    RIGHT_BELT_CONVEYOR,
//    LEFT_BELT_CONVEYOR,
//    CLEAR
//};

class Stage
{
private:
    int BlockNum = 0;

public:
    void Initialize();
    void Release();
    void Update();
    void Render(const DirectX::XMMATRIX& view, const DirectX::XMMATRIX& projection, const DirectX::XMFLOAT4& light_dir);	//	ï`âÊä÷êî

    void CreateBlock();
};