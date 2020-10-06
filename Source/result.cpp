#include "result.h"

#include "game.h"
#include <stdio.h>

void Result::Initialize()
{

}

void Result::Release()
{

}

void Result::Update()
{

}

void Result::Render()
{
    // Title•\Ž¦ ////////////////////
    //if (flash_timer % 30 )
    //{

    //}
    sprintf_s(str, "RESULT %d", GAME.score);

    if (GAME.score < 1000)
    {
        sprintf_s(comment, "You are noob!!!");
    }
    if (GAME.score > 1000 && GAME.score < 7000)
    {
        sprintf_s(comment, "Thank you for playing.");
    }
    if (GAME.score > 7000 && GAME.score < 9900)
    {
        sprintf_s(comment, "Congratulation!!");
    }
    if (GAME.score == 10000)
    {
        sprintf_s(comment, "ALL PERFECT!!!");
    }
}