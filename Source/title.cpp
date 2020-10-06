#include "title.h"
#include "my_mesh.h"
#include "framework.h"

#include<stdio.h>

MyMesh Line;

void Title::Initialize()
{
    flash_timer = 0;
}

void Title::Release()
{
    Line.Release();
}

void Title::Update()
{
    flash_timer++;
    //Å@ê¸Çï\é¶  /////////////////////////////////////////////////

    Line.Initialize();
    Line.SetPrimitive(new GeometricRect(FRAMEWORK.getDevice()));
    Line.color = DirectX::XMFLOAT4(1.0f, 0.5f, 0.4f, 1.0f);
    Line.scale = DirectX::XMFLOAT3(16.0f, 20.0f, 2.0f);
    Line.pos = { 0.0f, 0.1f, -5.0f };
    //////////////////////////////////////////////////////////////
}

void Title::Render()
{
    blender::Set(blender::ALPHA);
    Line.Render(view, projection, light_direction);
    sprintf_s(push, "push to SPACE");
    sprintf_s(str, "Final Defense Line");
}