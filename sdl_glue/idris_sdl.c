#include "idris_sdl.h"

void sdl_free(void* ptr) {
    free(ptr);
}

const char* sdl_get_error() {
    return SDL_GetError();
}

int sdl_init(int flags) {
    return SDL_Init(flags);
}

void sdl_quit() {
    SDL_Quit();
}

void* sdl_create_window(const char* title, int x, int y, int w, int h,
                        int flags) {
    SDL_Window* window = SDL_CreateWindow(title, x, y, w, h, flags);
    return (void*) window;
}

void sdl_destroy_window(void* window) {
    SDL_DestroyWindow((SDL_Window*) window);
}

void* sdl_create_renderer(void* win, int index, int flags) {
    SDL_Window* window = (SDL_Window*) win;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, index, flags);
    return (void*) renderer;
}

void sdl_destroy_renderer(void* rnd) {
    SDL_Renderer* renderer = (SDL_Renderer*) rnd;
    SDL_DestroyRenderer(renderer);
}

int sdl_render_clear(void* rnd) {
    SDL_Renderer* renderer = (SDL_Renderer*) rnd;
    return SDL_RenderClear(renderer);
}

void sdl_render_present(void* rnd) {
    SDL_Renderer* renderer = (SDL_Renderer*) rnd;
    SDL_RenderPresent(renderer);
}

int sdl_render_set_draw_color(void* rnd, int r, int g, int b, int a) {
    SDL_Renderer* renderer = (SDL_Renderer*) rnd;
    return SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

int sdl_render_draw_point(void* rnd, int x, int y) {
    SDL_Renderer* renderer = (SDL_Renderer*) rnd;
    return SDL_RenderDrawPoint(renderer, x, y);
}

int sdl_render_draw_line(void* rnd, int x1, int y1, int x2, int y2) {
    SDL_Renderer* renderer = (SDL_Renderer*) rnd;
    return SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

int sdl_render_draw_rect(void* rnd, int x, int y, int w, int h) {
    SDL_Renderer* renderer = (SDL_Renderer*) rnd;
    SDL_Rect rect = { x, y, w, h };
    return SDL_RenderDrawRect(renderer, &rect);
}

int sdl_render_fill_rect(void* rnd, int x, int y, int w, int h) {
    SDL_Renderer* renderer = (SDL_Renderer*) rnd;
    SDL_Rect rect = { x, y, w, h };
    return SDL_RenderFillRect(renderer, &rect);
}

void* sdl_poll_event() {
    SDL_Event* evt = malloc(sizeof(SDL_Event));
    int ret = SDL_PollEvent(evt);
    if (!ret)
        evt = NULL;
    return (void*) evt;
}

int sdl_get_event_type(void* evt) {
    SDL_Event* event = evt;
    return (int) event->type;
}

sdl_raw_mousebuttonevent* sdl_get_mouse_button_event(void* evt) {
    SDL_Event* event = (SDL_Event*) evt;
    sdl_raw_mousebuttonevent* mevt = malloc(sizeof(sdl_raw_mousebuttonevent));
    mevt->button = event->button.button;
    mevt->state = event->button.state;
    mevt->clicks = event->button.clicks;
    mevt->x = event->button.x;
    mevt->y = event->button.y;
    return mevt;
}

void sdl_free_raw_mousebuttonevent(sdl_raw_mousebuttonevent* evt) {
    free(evt);
}

sdl_raw_keyboardevent* sdl_get_keyboard_event(void* evt) {
    SDL_Event* event = (SDL_Event*) evt;
    sdl_raw_keyboardevent* kevt = malloc(sizeof(sdl_raw_keyboardevent));
    kevt->type = event->key.type;
    kevt->state = event->key.state;
    kevt->repeat = event->key.repeat;
    kevt->scancode = event->key.keysym.scancode;
    kevt->keycode = event->key.keysym.sym;
    kevt->mod = event->key.keysym.mod;
    return kevt;
}

void sdl_free_raw_keyboardevent(sdl_raw_mousebuttonevent* evt) {
    free(evt);
}

void sdl_delay(int ms) {
    SDL_Delay(ms);
}