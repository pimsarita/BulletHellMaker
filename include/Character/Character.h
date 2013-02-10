#ifndef CHARACTER_H
#define CHARACTER_H

#include <map>
#include <list>
#include <vector>

#include "TinyXml/tinyxml.h"
#include "Painter/Painter.h"
#include "Sonido/Sonido.h"
#include "Input/Input.h"
#include "Spells/Bullet.h"
#include "Spells/Pattern.h"

class Character
{
    Sonido* sonido;
    Painter* painter;
    Receiver* receiver;
    int x,y;
    int velocity;
    bool shooting;
    std::string orientation;

    //Sprites animation
    int animation_velocity;
    int animation_iteration;
    int current_sprite;
    std::map< std::string,std::vector<Image*> >sprites;

    //Patterns and bullets
    std::map<std::string,Bullet*> bullets;
    std::vector<Pattern*> patterns;
    std::list<Pattern*>* active_patterns;

public:
    Character(Sonido* sonido,Painter* painter,Receiver* receiver,std::string directory);
    void logic(int stage_velocity);
    //logic sub functions
    void animationControl();
    void inputControl();
    void spellControl(int stage_velocity);

    void render();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    std::list<Pattern*>* getActivePatterns();
};

#endif
