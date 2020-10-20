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
        pSceneManager.setChangeScene(state_title);
    }
}

void Clear::render(void)
{
    pFramework.sprites[0]->Render(pFramework.getContext(), 0, 0, 1920, 1080, 0, 0, 1920, 1080);
}

void Clear::end(void)
{

}