#include <SFML/Graphics.h>
#include <string.h>
#include "my.h"
#include "my_macros.h"
#include "graphics.h"

void destroy_screen(screen_t *screen)
{
    sfRenderWindow_destroy(screen->window);
}

void clear_screen(screen_t *screen)
{
    memset(screen->pixels, FALSE, sizeof(screen->pixels));
}

int initialize_screen(screen_t *screen)
{
    sfVideoMode mode = {WIDTH_BASE, HEIGHT_BASE, 32};

    screen->window = sfRenderWindow_create(mode, "Chip 8", sfResize | sfClose, NULL);
    if (screen->window == NULL)
        return display_error("Unable to load the window\n");
    clear_screen(screen);
    screen->pixel_height = HEIGHT_BASE / PIXEL_BY_HEIGHT;
    screen->pixel_width = WIDTH_BASE / PIXEL_BY_WIDTH;
    return SUCCESS;
}
