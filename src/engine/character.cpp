//
// Created by Савелий Никулин on 28.07.2024.
//

#include "character.h"

sengine::character::character() {
    fov = 90;
    d_angle = 0;
    speed = 40;
}

void sengine::character::move(sengine::vector d, float delta) {
    pos.x += d.dx * speed * delta;
    pos.y += d.dy * speed * delta;
}

void sengine::character::rotate(const float angle) {
    d_angle += angle;
}


