//
// Created by Савелий Никулин on 27.07.2024.
//

#include "object.h"

namespace sengine {
    object::object(): pos(0, 0) {
    }

    object::object(const point &pos, float w, float h) :
        pos(pos), w(w), h(h) {

    }

    bool object::isInteract(const object &o) const {
        return !(pos.x + w < o.pos.x || o.pos.x + o.w < pos.x || pos.y + h < o.pos.y || o.pos.y + o.h < pos.y);
    }

    bool object::isInteract(float x, float y) const {
        return (x >= pos.x && x <= pos.x + w && y >= pos.y && y <= pos.y + h);
    }
}
