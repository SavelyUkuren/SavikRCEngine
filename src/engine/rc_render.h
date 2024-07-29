//
// Created by Савелий Никулин on 29.07.2024.
//

#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL.h>

#include <vector>

#include "interfaces/IScene.h"
#include "character.h"
#include "components/object.h"
#include "math/se_math.h"
#include "math/point.h"
#include "math/line.h"

class rc_render {

    SDL_Renderer *render;
    IScene *scene;
    sengine::character *player;

    float maxRayDistance = 300;
    float rayCount = 640;
    float rayStep = 1;

    float wallScale = 40;

    int w_width;
    int w_height;
public:
    rc_render(
        SDL_Renderer *render,
        int w_width, int w_height,
        IScene *scene,
        sengine::character *player);

    void draw();

private:
    std::vector<sengine::line> castRays();
};



#endif //RENDER_H
