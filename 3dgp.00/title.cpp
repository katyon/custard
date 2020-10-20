// インクルード ----------------------------------------------------------------------------------
#include "framework.h"
#include "scene_manager.h"
#include "title.h"

// 関数 ----------------------------------------------------------------------------------------
void Title::init(void)
{

}

void Title::update(void)
{
    if (GetAsyncKeyState(VK_SPACE) & 1)
    {
        pSceneManager.setChangeScene(state_select);
    }
}

void Title::render(void)
{
    pFramework.sprites[0]->Render(pFramework.getContext(), 0, 0, 1920, 1080, 0, 0, 1920, 1080);
}

void Title::end(void)
{

}