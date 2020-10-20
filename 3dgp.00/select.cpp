// インクルード ----------------------------------------------------------------------------------
#include "framework.h"
#include "scene_manager.h"
#include "select.h"

// 関数 ----------------------------------------------------------------------------------------
void _Select::init(void)
{
    map_num = 0;
}

void _Select::update(void)
{


    if (GetAsyncKeyState(VK_SPACE) & 1)
    {
        pSceneManager.setChangeScene(state_game);
    }
}

void _Select::render(void)
{
    //pFramework.sprites[0]->Render(pFramework.getContext(), 0, 0, 1920, 1080, 0, 0, 1920, 1080);
}

void _Select::end(void)
{

}