//
// Created by Савелий Никулин on 27.07.2024.
//

#ifndef ISCENE_H
#define ISCENE_H

#include <vector>

#include "../components/object.h"
#include "../character.h"

class IScene {
public:
    std::vector<sengine::object*> objects;
    sengine::character *player;

    virtual void setup() {}
    virtual void eventUpdate() {}
    virtual void update(const float delta) {}
    virtual void draw() {}

    virtual ~IScene() = default;
};

#endif //ISCENE_H
