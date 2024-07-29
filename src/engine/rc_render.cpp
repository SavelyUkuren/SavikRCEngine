//
// Created by Савелий Никулин on 29.07.2024.
//

#include "rc_render.h"

rc_render::rc_render(SDL_Renderer *render,
    int w_width,
    int w_height,
    IScene *scene,
    sengine::character *player)
{
    this->render = render;
    this->w_width = w_width;
    this->w_height = w_height;
    this->scene = scene;
    this->player = player;


}

void rc_render::draw() {

    std::vector<sengine::line> lines = castRays();

    for (int i = 0; i < lines.size(); i++) {

        const float distance = lines[i].length();
        if (distance > maxRayDistance - 2) continue;

        // const float wallHeight = (w_height / (distance * tan(player->fov / 2.0f * M_PI / 180.0f))) * wallScale;
        const float wallHeight = (w_height / distance) * wallScale;
        SDL_FRect wallR {
            w_width / rayCount * i,
            w_height / 2 - wallHeight / 2,
            w_width / rayCount,
            wallHeight
        };

        const float wallColor = (1 - (distance / maxRayDistance)) * 255;
        SDL_SetRenderDrawColor(render, wallColor, wallColor, wallColor, 255);
        SDL_RenderFillRect(render, &wallR);
    }


    SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
    for (sengine::object *o : scene->objects) {
        SDL_FRect rect {
            o->pos.x, o->pos.y,
            o->w, o->h
        };
        SDL_RenderRect(render, &rect);
    }

    for (sengine::line &l : lines) {
        SDL_RenderLine(render, l.x1, l.y1, l.x2, l.y2);
    }
}

std::vector<sengine::line> rc_render::castRays() {
    std::vector<sengine::line> lines;
    const float ray_angle = player->fov / rayCount;
    float temp_angle = player->d_angle;
    for (int i = 0; i < rayCount; i += 1) {
        sengine::point p(0, 0);
        bool hitObject = false;
        float distance = 0;

        for (float j = 0; j < maxRayDistance; j += rayStep) {

            p.x = player->pos.x + (player->w / 2) + j * cos(se_math::to_radian(temp_angle));
            p.y = player->pos.y + (player->h / 2) + j * sin(se_math::to_radian(temp_angle));

            for (const sengine::object *o : scene->objects) {
                if (o->isInteract(p.x, p.y)) {
                    hitObject = true;
                    distance = j;
                    break;
                }
            }
            if (hitObject) break;

        }

        sengine::line l {
            player->pos.x + (player->w / 2),
            player->pos.y + (player->h / 2),
            p.x,
            p.y
        };

        lines.push_back(l);
        temp_angle += ray_angle;
    }

    return lines;
}
