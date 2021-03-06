#pragma once

// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
#define pClear Clear::getInstance()
class Clear
{
public:
    static  inline Clear& getInstance()
    {
        static Clear instance;
        return instance;
    }

    void init(void);
    void update(void);
    void render(void);
    void end(void);

private:
};