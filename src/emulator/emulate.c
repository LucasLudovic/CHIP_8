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
#include "emulator/cpu.h"
#include "emulator/rom.h"

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
void initialize_memory_fonts(Uint8 *memory)
{
    memory[0]=0xF0;memory[1]=0x90;memory[2]=0x90;memory[3]=0x90; memory[4]=0xF0; // O
    memory[5]=0x20;memory[6]=0x60;memory[7]=0x20;memory[8]=0x20;memory[9]=0x70; // 1
    memory[10]=0xF0;memory[11]=0x10;memory[12]=0xF0;memory[13]=0x80; memory[14]=0xF0; // 2
    memory[15]=0xF0;memory[16]=0x10;memory[17]=0xF0;memory[18]=0x10;memory[19]=0xF0; // 3
    memory[20]=0x90;memory[21]=0x90;memory[22]=0xF0;memory[23]=0x10;memory[24]=0x10; // 4
    memory[25]=0xF0;memory[26]=0x80;memory[27]=0xF0;memory[28]=0x10;memory[29]=0xF0; // 5
    memory[30]=0xF0;memory[31]=0x80;memory[32]=0xF0;memory[33]=0x90;memory[34]=0xF0; // 6
    memory[35]=0xF0;memory[36]=0x10;memory[37]=0x20;memory[38]=0x40;memory[39]=0x40; // 7
    memory[40]=0xF0;memory[41]=0x90;memory[42]=0xF0;memory[43]=0x90;memory[44]=0xF0; // 8
    memory[45]=0xF0;memory[46]=0x90;memory[47]=0xF0;memory[48]=0x10;memory[49]=0xF0; // 9
    memory[50]=0xF0;memory[51]=0x90;memory[52]=0xF0;memory[53]=0x90;memory[54]=0x90; // A
    memory[55]=0xE0;memory[56]=0x90;memory[57]=0xE0;memory[58]=0x90;memory[59]=0xE0; // B
    memory[60]=0xF0;memory[61]=0x80;memory[62]=0x80;memory[63]=0x80;memory[64]=0xF0; // C
    memory[65]=0xE0;memory[66]=0x90;memory[67]=0x90;memory[68]=0x90;memory[69]=0xE0; // D
    memory[70]=0xF0;memory[71]=0x80;memory[72]=0xF0;memory[73]=0x80;memory[74]=0xF0; // E
    memory[75]=0xF0;memory[76]=0x80;memory[77]=0xF0;memory[78]=0x80;memory[79]=0x80; // F
}

static
void init_cpu(emulator_t *emulator)
{
    emulator->cpu = malloc(sizeof(chip_cpu_t));
    if (emulator->cpu == NULL)
        return;
    memset(emulator->cpu, 0, sizeof(*(emulator->cpu)));
    initialize_memory_fonts(emulator->cpu->memory);
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
        cpu->sound_timer -= 1;
}

int emulate_chip_8(const char *path)
{
    emulator_t emulator = { 0 };
    sfClock *clock = sfClock_create();
    sfTime my_time = { 0 };
    int milli_seconds = 0;
    int timer = 0;

    srand(time(NULL));
    if (clock == NULL)
        return FAILURE;
    init_cpu(&emulator);
    if (initialize_screen(&emulator) ==  FAILURE)
        return destroy_end(&emulator, clock);
    sfRenderWindow_display(emulator.screen->window);
    load_rom(emulator.cpu, path);
    while (sfRenderWindow_isOpen(emulator.screen->window)) {
        my_time = sfClock_getElapsedTime(clock);
        milli_seconds = sfTime_asMilliseconds(my_time);
        check_event(&emulator);
        if (milli_seconds > FREQUENCE_IN_MS) {
            interpret(&emulator);
            timer += 1;
            sfClock_restart(clock);
            update_counter(emulator.cpu);
        }
        if (timer >= 4) {
            update_screen(emulator.screen);
            timer = 0;
        }
    }
    destroy_end(&emulator, clock);
    return SUCCESS;
}
