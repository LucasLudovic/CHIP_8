#ifndef GRAPHICS_H_
    #define GRAPHICS_H_
    #define PIXEL_BY_WIDTH 64
    #define PIXEL_BY_HEIGHT 32
    #define WIDTH_BASE 1920
    #define HEIGHT_BASE 1080
    #include <SFML/Graphics.h>

typedef struct screen_s {
    sfRenderWindow *window;
    unsigned char pixels[PIXEL_BY_HEIGHT][PIXEL_BY_WIDTH];
    unsigned long long pixel_height;
    unsigned long long pixel_width;
}screen_t;

int initialize_screen(screen_t *screen);
void clear_screen(screen_t *screen);
void destroy_screen(screen_t *screen);

#endif
