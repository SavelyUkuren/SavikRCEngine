//
// Created by Савелий Никулин on 27.07.2024.
//

#include "TestScene.h"

TestScene::TestScene() {
    sengine::object *w1 = new sengine::object({10, 10}, 300, 5);
    sengine::object *w2 = new sengine::object({10, 10}, 5, 150);
    sengine::object *w3 = new sengine::object({10, 150}, 200, 5);
    sengine::object *w4 = new sengine::object({300, 10}, 5, 150);

    sengine::object *w5 = new sengine::object({40, 50}, 30, 60);
    sengine::object *w6 = new sengine::object({100, 0}, 30, 90);
    sengine::object *w7 = new sengine::object({260, 100}, 30, 30);

    player = new sengine::character();
    player->pos = sengine::point(20, 40);
    player->name = "Savely";
    player->d_angle = 0;//56.14;

    objects.push_back(w1);
    objects.push_back(w2);
    objects.push_back(w3);
    objects.push_back(w4);

    objects.push_back(w5);
    objects.push_back(w6);
    objects.push_back(w7);
}

void TestScene::setup() {
    IScene::setup();

}

void TestScene::eventUpdate() {
    IScene::eventUpdate();
}

void TestScene::update(const float delta) {
    IScene::update(delta);

    float mouseDX, mouseDY = 0;
    SDL_GetRelativeMouseState(&mouseDX, &mouseDY);
    SDL_SetRelativeMouseMode(true);

    player->rotate(mouseDX / 4);

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    sengine::vector direction(0, 0);
    if (keystate[SDL_SCANCODE_W]) {
        float d = (player->d_angle + player->fov / 2) * M_PI / 180;
        direction.dx = cos(d);
        direction.dy = sin(d);
    }
    if (keystate[SDL_SCANCODE_S]) {
        float d = (player->d_angle + player->fov / 2) * M_PI / 180;
        direction.dx = -cos(d);
        direction.dy = -sin(d);
    }
    if (keystate[SDL_SCANCODE_A]) {
        float d = (player->d_angle + player->fov / 2 - 90) * M_PI / 180;
        direction.dx = cos(d);
        direction.dy = sin(d);
    }
    if (keystate[SDL_SCANCODE_D]) {
        float d = (player->d_angle + player->fov / 2 + 90) * M_PI / 180;
        direction.dx = cos(d);
        direction.dy = sin(d);
    }
    player->move(direction, delta);

}

void TestScene::draw() {
    IScene::draw();
}

TestScene::~TestScene() {
    player = nullptr;
}
