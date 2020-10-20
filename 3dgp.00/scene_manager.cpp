// インクルード ----------------------------------------------------------------------------------
#include "scene_manager.h"

#include "clear.h"
#include "game.h"
#include "select.h"
#include "stage.h"
#include "title.h"

// 関数 ----------------------------------------------------------------------------------------
void SceneManager::init(void)
{
    pSceneTitle.init();
    change_scene = keep;
    scene_state = state_title;
    scene_buffer = keep;
}

void SceneManager::update(void)
{
    if (change_scene != keep)
    {
        pSceneManager.changeSceneStateInit(change_scene);
    }

    switch (scene_state)
    {
    case state_title:
        pSceneTitle.update();
        break;
    case state_select:
        pSceneSelect.update();
        break;
    case state_game:
        pSceneGame.update();
        break;
    case state_clear:
        pSceneClear.update();
        break;
    case relay:
        pRelay.update();
        break;
    default: break;
    }
}

void SceneManager::render(void)
{
    switch (scene_state)
    {
    case state_title:
        pSceneTitle.render();
        break;
    case state_select:
        pSceneSelect.render();
        break;
    case state_game:
        pSceneGame.render();
        break;
    case state_clear:
        pSceneClear.render();
        break;
    default: break;
    }
}

void SceneManager::changeSceneStateInit(SCENES _next_scene)
{
    // 現在のシーンの終了処理
    switch (getSceneState())
    {
    case state_title:
        pSceneTitle.end();
        break;
    case state_select:
        pSceneSelect.end();
        break;
    case state_game:
        pSceneGame.end();
        break;
    case state_clear:
        pSceneClear.end();
        break;
    default:
        break;
    }

    // シーン遷移時に初期化
    switch (_next_scene)
    {
    case state_title:
        pSceneTitle.init();
        break;
    case state_select:
        pSceneSelect.init();
        break;
    case state_game:
        pSceneGame.init();
        break;
    case state_clear:
        pSceneClear.init();
        break;
    default:
        break;
    }

    setChangeScene(keep);
    setSceneState(relay);
    setSceneBuffer(_next_scene);
}

void SceneManager::setSceneState(SCENES _scene_state)
{
    scene_state = _scene_state;
}
void SceneManager::setChangeScene(SCENES _change_scene)
{
    change_scene = _change_scene;
}
void SceneManager::setSceneBuffer(SCENES _scene_buffer)
{
    scene_buffer = _scene_buffer;
}
int SceneManager::getSceneState()
{
    return scene_state;
}
int SceneManager::getChangeScene()
{
    return change_scene;
}
SCENES SceneManager::getSceneBuffer()
{
    return scene_buffer;
}

// Title
void SceneTitle::init(void)
{
    pTitle.init();
    pSceneManager.playBGM = true;
    timer = 0;
}

void SceneTitle::update(void)
{
    pTitle.update();
    timer++;
}

void SceneTitle::render(void)
{
    pTitle.render();
}

void SceneTitle::end(void)
{
    pTitle.end();
}

// Select
void SceneSelect::init(void)
{
    p_Select.init();
    timer = 0;
}

void SceneSelect::update(void)
{
    p_Select.update();
    timer++;
}

void SceneSelect::render(void)
{
    p_Select.render();
}

void SceneSelect::end(void)
{
    p_Select.end();
}

// Game
void SceneGame::init(void)
{
    pGame.Initialize();
    timer = 0;
}

void SceneGame::update(void)
{

    pGame.Update();
    timer++;
}

void SceneGame::render(void)
{
    pGame.Render();
}

void SceneGame::end(void)
{
    pStage.Release();
}

// Clear
void SceneClear::init(void)
{
    pClear.init();
    timer = 0;
}

void SceneClear::update(void)
{

    pClear.update();
    timer++;
}

void SceneClear::render(void)
{
    pClear.render();
}

void SceneClear::end(void)
{
    pClear.end();
}

// Relay
void Relay::update(void)
{
    pSceneManager.setSceneState(pSceneManager.getSceneBuffer());
    pSceneManager.setSceneBuffer(keep);
}