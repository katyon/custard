#pragma once

// ’è” ----------------------------------------------------------------

// ƒNƒ‰ƒX --------------------------------------------------------------
#define p_Select _Select::getInstance()
class _Select
{
public:
    static  inline _Select& getInstance()
    {
        static _Select instance;
        return instance;
    }

    void init(void);
    void update(void);
    void render(void);
    void end(void);

    int map_num = 0;

private:
};