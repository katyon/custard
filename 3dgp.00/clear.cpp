// インクルード ----------------------------------------------------------------------------------
#include "framework.h"
#include "scene_manager.h"
#include "clear.h"

// 関数 ----------------------------------------------------------------------------------------
void Clear::init(void)
{

}

void Clear::update(void)
{
    if (GetAsyncKeyState(VK_SPACE) & 1)
    {
        pSceneManager.playChoice = true;

        pSceneManager.setChangeScene(state_title);
    }
}


void Clear::render(void)
{
    if (pSceneClear.timer % 60 > 30)
    {
        pFramework.sprites[5]->Render(pFramework.getContext(), 0, 0, 1920, 1080, 0, 0, 1920, 1080);
    }
    else
    {
        pFramework.sprites[5]->Render(pFramework.getContext(), 0, 0, 1920, 1080, 1920, 0, 1920, 1080);
    }
}

void Clear::end(void)
{

}