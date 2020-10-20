#pragma once
#include	"directxmath.h"

// 定数 ----------------------------------------------------------------
enum SCENES
{
    keep,

    state_title,
    state_select,
    state_game,
    state_clear,

    relay
};

// クラス --------------------------------------------------------------
#define pSceneManager SceneManager::getInstance()
class SceneManager
{
public:
    static  inline SceneManager& getInstance()
    {
        static SceneManager instance;
        return instance;
    }


    void init(void);
    void update(void);
    void render(void);
    void changeSceneStateInit(SCENES _next_scene);    // シーン遷移処理

    void setChangeScene(SCENES _change_scene);  // シーン遷移時に使用
    void setSceneState(SCENES _scene_state);
    void setSceneBuffer(SCENES _scene_buffer);
    int getSceneState();
    int getChangeScene();
    SCENES getSceneBuffer();

    bool playBGM = false;
    bool playChoice = false;
    bool playDeath = false;
    bool playReturn = false;

private:
    SCENES change_scene = keep;
    SCENES scene_state = state_title;
    SCENES scene_buffer = keep;
};

#define pSceneTitle SceneTitle::getInstance()
class SceneTitle
{
public:
    static  inline SceneTitle& getInstance()
    {
        static SceneTitle instance;
        return instance;
    }

    void init(void);
    void update(void);
    void render(void);
    void end(void);

    int timer = 0;
private:
};

#define pSceneSelect SceneSelect::getInstance()
class SceneSelect
{
public:
    static  inline SceneSelect& getInstance()
    {
        static SceneSelect instance;
        return instance;
    }

    void init(void);
    void update(void);
    void render(void);
    void end(void);

    int timer = 0;
private:
};

#define pSceneGame SceneGame::getInstance()
class SceneGame
{
public:
    static  inline SceneGame& getInstance()
    {
        static SceneGame instance;
        return instance;
    }

    void init(void);
    void update(void);
    void render(void);
    void end(void);

    int timer = 0;
private:
};

#define pSceneClear SceneClear::getInstance()
class SceneClear
{
public:
    static  inline SceneClear& getInstance()
    {
        static SceneClear instance;
        return instance;
    }

    void init(void);
    void update(void);
    void render(void);
    void end(void);

    int timer = 0;
private:
};

#define pRelay Relay::getInstance()
class Relay
{
public:
    static  inline Relay& getInstance()
    {
        static Relay instance;
        return instance;
    }

    void update(void);

private:
};