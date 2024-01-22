/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Emulate
** Main loop function of the emulator
*/

#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <string.h>
#include "emulator/emulate.h"
#include "display/graphics.h"
#include "input/events.h"
#include "my_macros.h"

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
        if (emulator->action != NULL)
            free(emulator->action);
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
    emulator->action = malloc(sizeof(action_t));
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
    sfTime my_time = { 0 };
    int seconds = 0;

    srand(time(NULL));
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
        my_time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asMilliseconds(my_time);
        if ( seconds > FRAME_IN_MS) {
            check_event(&emulator);
            update_screen(emulator.screen);
        }
    }
    destroy_end(&emulator, clock);
    return SUCCESS;
}
