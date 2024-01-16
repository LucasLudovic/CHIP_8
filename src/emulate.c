#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <string.h>
#include <stdio.h>
#include "emulate.h"
#include "graphics.h"
#include "my_macros.h"
#include "events.h"

static
int destroy_end(emulator_t *emulator, sfClock *clock)
{
    if (clock != NULL)
        sfClock_destroy(clock);
    if (emulator != NULL) {
        if (emulator->screen != NULL) {
            if (emulator->screen->window != NULL)
                sfRenderWindow_destroy(emulator->screen->window);
            free(emulator->screen);
        }
        if (emulator->cpu != NULL)
            free(emulator->cpu);
    }
    return FAILURE;
}

static
void init_cpu(emulator_t *emulator)
{
    emulator->cpu = malloc(sizeof(chip_cpu_t));
    if (emulator->cpu == NULL)
        return;
    memset(emulator->cpu, 0, sizeof(*(emulator->cpu)));
    emulator->cpu->program_counter = START_ADDRESS;
}

static
void update_counter(chip_cpu_t *cpu)
{
    if (cpu == NULL)
        return;
    if (cpu->sys_timer > 0)
        cpu->sys_timer -= 1;
    if (cpu->sound_timer > 0)
        cpu->sys_timer -= 1;
}

int emulate_chip_8(void)
{
    emulator_t emulator = { 0 };
    sfClock *clock = sfClock_create();
    sfTime time = { 0 };
    int seconds = 0;

    if (clock == NULL)
        return FAILURE;
    init_cpu(&emulator);
    if (initialize_screen(&emulator) ==  FAILURE)
        return destroy_end(&emulator, clock);
    for (int i = 0; i < PIXEL_BY_HEIGHT; i += 1)
        for (int j = 0; j < PIXEL_BY_WIDTH; j += 1)
            emulator.screen->pixels[i][j] = (j % (i + 1)) != 0;
    sfRenderWindow_display(emulator.screen->window);
    while (sfRenderWindow_isOpen(emulator.screen->window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asMilliseconds(time);
        if ( seconds > FRAME_IN_MS) {
            check_event(&emulator);
            update_screen(emulator.screen);
        }
    }
    return SUCCESS;
}
