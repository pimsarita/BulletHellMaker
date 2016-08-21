#ifndef ENEMY_H
#define ENEMY_H

#include <map>
#include <list>
#include <vector>

#include "../Rosalila/TinyXml/tinyxml.h"
#include "../Rosalila/RosalilaGraphics/RosalilaGraphics.h"
#include "../Rosalila/RosalilaSound/RosalilaSound.h"
#include "../Rosalila/RosalilaInputs/RosalilaInputs.h"
#include "Bullet.h"
#include "Pattern.h"
#include "Character.h"
#include "Player.h"

class Enemy : public Character
{
public:
    std::map<int, vector<Modifier*>* >modifiers;
    double angle;
    double angle_change;
    Player*player;

    string score_upload_message;
    bool flag_begin_upload;

    Enemy(RosalilaSound* sonido,RosalilaGraphics* painter,Receiver* receiver,std::string name,Player*player,int sound_channel_base);
    void logic(int stage_velocity, string stage_name, int global_iteration, string username);
    void modifiersControl();
    void bottomRender();
    void topRender();
    void loadModifiersFromXML();
    virtual void addActivePattern(Pattern* pattern);
    void aimPlayer(Pattern* pattern);
};

#endif
