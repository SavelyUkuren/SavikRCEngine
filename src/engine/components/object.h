//
// Created by Савелий Никулин on 27.07.2024.
//

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "../math/point.h"

namespace sengine {

    class object {
    public:
        point pos; // position
        float w, h = 0; // width and height
        std::string name = "";

        object();
        object(const point &pos, float w, float h);

        virtual void setup() {}
        virtual void update() {}

        bool isInteract(const object &o) const;
        bool isInteract(float x, float y) const;
    };

}

#endif //OBJECT_H
