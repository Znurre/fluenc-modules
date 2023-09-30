#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>

struct Event
{
    uint32_t type;

    SDL_KeyboardEvent *key;
    SDL_MouseMotionEvent *motion;
    SDL_MouseButtonEvent *button;
};

struct Event *SDL_WaitEventEx(struct Event *events)
{
    SDL_Event event;

    SDL_WaitEvent(&event);

    events->type = event.type;

    memcpy(events->key, &event.key, sizeof(SDL_KeyboardEvent));
    memcpy(events->motion, &event.motion, sizeof(SDL_MouseMotionEvent));
    memcpy(events->button, &event.button, sizeof(SDL_MouseButtonEvent));

    return events;
}

SDL_Rect *SDL_RenderGetViewportEx(SDL_Renderer *renderer, SDL_Rect *rect)
{
    SDL_RenderGetViewport(renderer, rect);

    return rect;
}

SDL_Surface *RenderText_Solid(TTF_Font *font, const char *text, int r, int g, int b)
{
    if (!font)
    {
        printf("no font!!\n");
    }

    SDL_Color color = { r, g, b, 0 };

    return TTF_RenderText_Blended(font, text, color);
}

int GetSurfaceWidth(SDL_Surface *surface)
{
    return surface->w;
}

int GetSurfaceHeight(SDL_Surface *surface)
{
    return surface->h;
}
