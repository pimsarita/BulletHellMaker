#ifndef STG_H
#define STG_H

#include "../Rosalila/TinyXml/tinyxml.h"
#include "../Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "../Rosalila/RosalilaSound/RosalilaSound.h"
#include "../Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "../Rosalila/RosalilaGraphics/Animation.h"
#include "Character/Character.h"
#include "Character/Player.h"
#include "Character/Enemy.h"
#include "Stage/Stage.h"

class STG
{
public:
    Player*player;
    Enemy*enemy;
    Stage*stage;

    string game_mode;

    Animation you_win,you_loose;
    int frame;

    map<string,Button*>controls;

    Image*image_training_box;
    Image*image_training_x;
    Image*image_training_bar;
    Image*image_training_bar_fill;
    Image*image_training_text;
    Image*image_training_text_final;
    int current_training_transparency;
    int current_training_final_transparency;

    double parry_count;
    double parry_count_objective;
    double charge_destroy_count;
    double charge_destroy_count_objective;
    double parry_dash_count;
    double parry_dash_count_objective;

    STG(Player*player,Enemy*enemy,Stage*stage,string game_mode,map<string,Button*>controls);
    bool isOutOfBounds(int pos_x,int pos_y);
    void mainLoop();
    void logic();
    void render();
    void deletePatterns();
    void checkCharacterOutOfBounds();
    bool playerWon();
    bool enemyWon();
    void stageSelectModeInit();
    void win();
    void lose();
};

#endif