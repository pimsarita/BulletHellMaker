#include "Utility.h"

int iterate_slowdown_flag=0;
int current_slowdown_iteration=0;
bool slow_enabled=false;
bool game_over;
bool player_won;

Image* loading_image;
Image* error_image;
Image* sucess_image;

void initShooterUtility()
{
    loading_image = Rosalila()->Graphics->getTexture(assets_directory+"misc/messages/loading.png");
    error_image = Rosalila()->Graphics->getTexture(assets_directory+"misc/messages/error.png");
    sucess_image = Rosalila()->Graphics->getTexture(assets_directory+"misc/messages/sucess.png");
}

bool getGameOver()
{
    return game_over;
}

void setGameOver(bool game_over_param)
{
    game_over=game_over_param;
}

bool getPlayerWon()
{
    return player_won;
}

void setPlayerWon(bool player_won_param)
{
    player_won=player_won_param;
}

bool getIterateSlowdownFlag()
{
    return !isSlowActive() || iterate_slowdown_flag;
}

void slowExtraControl()
{
    //slow extra control
    if(isSlowActive())
    {
        iterate_slowdown_flag=false;
        current_slowdown_iteration++;
        if(current_slowdown_iteration>=3)
        {
            current_slowdown_iteration=0;
            iterate_slowdown_flag=true;
        }
    }
}

bool isSlowPressed()
{
    return Rosalila()->Receiver->isKeyDown(SDLK_x) || Rosalila()->Receiver->isJoyDown(5,0);
}

void disableSlow()
{
    slow_enabled=false;
}
void enableSlow()
{
    slow_enabled=true;
}
bool isSlowEnabled()
{
    return slow_enabled;
}
bool isSlowActive()
{
    return isSlowEnabled() && isSlowPressed();
}

double getSlowdown()
{
    int slowdown = 1.0;
    if(isSlowPressed() && isSlowEnabled())
        slowdown = 3.0;
    return slowdown;
}

Image* getLoadingImage()
{
    return loading_image;
}

Image* getErrorImage()
{
    return error_image;
}

Image* getSuccessImage()
{
    return sucess_image;
}

int getNotificationDuration()
{
    return 50;
}
