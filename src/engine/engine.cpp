//
// Created by Савелий Никулин on 27.07.2024.
//

#include "engine.h"

engine::engine(std::string title, const int width, const int height) {
    this->title = title;
    this->width = width;
    this->height = height;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL_Init error!" << std::endl;
        return;
    }

    if (SDL_CreateWindowAndRenderer(title.c_str(), width, height, 0, &window, &render)) {
        std::cerr << "SDL_CreateWindowAndRenderer error!" << std::endl;
        return;
    }

}

void engine::start() {
    setup();
    isRunning = true;
    update();
}

void engine::setup() {
    scene->setup();
}

void engine::update() {

    float delta = 0;
    Uint32 newTime = SDL_GetTicks();
    Uint32 oldTime = SDL_GetTicks();

    while (isRunning) {
        newTime = SDL_GetTicks();
        delta = static_cast<float>(newTime - oldTime) / 1000.0f;

        SDL_WarpMouseInWindow(window, width / 2, height / 2);

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT)
                isRunning = false;
        }
        scene->eventUpdate();
        scene->update(delta);
        //std::cout << scene->player->d_angle << std::endl;
        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        SDL_RenderClear(render);

        //scene->draw();
        if (rcRender != nullptr)
            rcRender->draw();

        SDL_RenderPresent(render);
        SDL_Delay(1.0f / maxFPS * 1000.0f);
        oldTime = newTime;
    }

}

void engine::setScene(IScene *scene) {
    this->scene = scene;
    rcRender = new rc_render(render, width, height, scene, scene->player);
}

engine::~engine() {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();

    render = nullptr;
    window = nullptr;
    rcRender = nullptr;
}
