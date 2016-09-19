#ifndef STAGE_H
#define STAGE_H

#include "../Character/Character.h"
#include "Layer.h"
#include "../Utility/Utility.h"
#include <map>

class Stage
{
public:
    std::vector<Layer*> back,front;
    std::string music_path;
    int bound_x1,bound_y1,bound_x2,bound_y2;
    int velocity;
    int iterator;
    string name;
    bool iterate_slowdown_flag;
    int current_slowdown_iteration;

    int layer_transparency;

    Stage();
    ~Stage();
    void dibujarBack();
    void dibujarFront();
    void drawLayer(Layer*layer);
    void loadFromXML(std::string name);
    void logic();
    void playMusic();
};

#endif
