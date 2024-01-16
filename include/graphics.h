#ifndef GRAPHICS_H_
    #define GRAPHICS_H_
    #define WIDTH_BASE 1920.f
    #define HEIGHT_BASE 1080.f
    #include <SFML/Graphics.h>
    #include "emulate.h"
    #include "graphics.h"
    #define FRAMERATE 60
    #define FRAME_IN_MS 17

int initialize_screen(emulator_t *emulator);
void update_screen(screen_t *screen);
void clear_screen(screen_t *screen);

#endif
