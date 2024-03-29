/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Graphics
** Functions to handle the game's graphics
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "emulator/emulate.h"
#include "display/graphics.h"
#include "my.h"
#include "my_macros.h"

void clear_screen(screen_t *screen)
{
    memset(screen->pixels, FALSE, sizeof(screen->pixels));
}

void update_screen(screen_t *screen)
{
    sfRectangleShape *pixel_normalize = sfRectangleShape_create();
    sfVector2f position = { 0 };
    sfVector2u window_size = { 0 };

    window_size = sfRenderWindow_getSize(screen->window);
    if (pixel_normalize == NULL)
        return;
    sfRenderWindow_clear(screen->window, sfBlack);
    sfRectangleShape_setSize(pixel_normalize, (sfVector2f){(float)window_size.x / (float)screen->pixel_width, (float)window_size.y / (float)screen->pixel_height});
    sfRectangleShape_setFillColor(pixel_normalize, sfWhite);
    for (size_t i = 0; i < PIXEL_BY_HEIGHT; i += 1) {
        for (size_t j = 0; j < PIXEL_BY_WIDTH; j += 1) {
            if (screen->pixels[i][j] == TRUE) {
                position.x = (float)(screen->pixel_width * j);
                position.y = (float)(screen->pixel_height * i);
                sfRectangleShape_setPosition(pixel_normalize, position);
                sfRenderWindow_drawRectangleShape(screen->window, pixel_normalize, NULL);
            }
        }
    }
    sfRenderWindow_display(screen->window);
}

int initialize_screen(emulator_t *emulator)
{
    sfVideoMode mode = {WIDTH_BASE, HEIGHT_BASE, 32};
    sfVector2u window_size = { 0 };

    emulator->screen = malloc(sizeof(screen_t));
    emulator->screen->window = sfRenderWindow_create(mode, "Chip 8", sfResize | sfClose, NULL);
    if (emulator->screen->window == NULL)
        return display_error("Unable to load the window\n");
    window_size = sfRenderWindow_getSize(emulator->screen->window);
    clear_screen(emulator->screen);
    emulator->screen->pixel_height = window_size.y / PIXEL_BY_HEIGHT;
    emulator->screen->pixel_width = window_size.x / PIXEL_BY_WIDTH;
    return SUCCESS;
}
