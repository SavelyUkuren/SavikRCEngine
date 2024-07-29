//
// Created by Савелий Никулин on 27.07.2024.
//

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <SDL3/SDL.h>

#include "interfaces/IScene.h"
#include "rc_render.h"

class engine {

    const float maxFPS = 60.0f;

    std::string title;
    int width, height = 0;
    bool isRunning = false;

    IScene *scene;

    SDL_Window *window;
    SDL_Renderer *render;

    rc_render *rcRender;

public:
    engine(std::string title, int width, int height);

    void start();

    void setup();
    void update();

    void setScene(IScene *scene);

    ~engine();
};



#endif //ENGINE_H
