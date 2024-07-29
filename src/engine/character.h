//
// Created by Савелий Никулин on 28.07.2024.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

#include "components/object.h"
#include "math/vector.h"

namespace sengine {
    class character: public object {

    public:
        float d_angle;
        float fov;
        float speed;

        character();

        void move(sengine::vector d, float delta);
        void rotate(const float angle);

    };
}



#endif //CHARACTER_H
