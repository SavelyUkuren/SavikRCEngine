//
// Created by Савелий Никулин on 27.07.2024.
//

#ifndef LINE_H
#define LINE_H

namespace sengine {
    struct line {
        float x1, y1, x2, y2;
        float length() const {
            return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        }

    };
}

#endif //LINE_H
