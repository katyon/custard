// インクルード ----------------------------------------------------------------------------------
#include "framework.h"
#include "scene_manager.h"
#include "select.h"

// 関数 ----------------------------------------------------------------------------------------
void _Select::init(void)
{
    map_num = 1;
}

void _Select::update(void)
{
    if (GetAsyncKeyState(VK_LEFT) & 1)
    {
        pSceneManager.playChoice = true;

        map_num--;
    }
    if (GetAsyncKeyState(VK_RIGHT) & 1)
    {
        pSceneManager.playChoice = true;

        map_num++;
    }
    if (map_num < 1)
    {
        map_num = 1;
    }
    if (map_num > 3)
    {
        map_num = 3;
    }

    if (GetAsyncKeyState(VK_SPACE) & 1)
    {
        pSceneManager.playChoice = true;

        pSceneManager.setChangeScene(state_game);
    }
}

void _Select::render(void)
{
    switch (map_num)
    {
    case 1:
    pFramework.sprites[2]->Render(pFramework.getContext(), 0, 0, 1920, 1080, 0, 0, 1920, 1080);
        break;
    case 2:
        pFramework.sprites[3]->Render(pFramework.getContext(), 0, 0, 1920, 1080, 0, 0, 1920, 1080);
        break;
    case 3:
        pFramework.sprites[4]->Render(pFramework.getContext(), 0, 0, 1920, 1080, 0, 0, 1920, 1080);
        break;
    default:
        break;
    }
}

void _Select::end(void)
{

}