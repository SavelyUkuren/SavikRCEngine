//
// Created by Савелий Никулин on 27.07.2024.
//

#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include <iostream>
#include <SDL3/SDL.h>

#include "../engine/character.h"
#include "../engine/engine.h"

class TestScene : public IScene {

public:
    TestScene();

    void setup() override;
    void eventUpdate() override;
    void update(const float delta) override;
    void draw() override;

    ~TestScene();
};



#endif //TEST_SCENE_H
