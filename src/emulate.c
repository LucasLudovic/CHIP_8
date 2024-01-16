#include <stdlib.h>
#include <string.h>
#include "emulate.h"
#include "my_macros.h"

static
void init_cpu(chip_cpu_t *cpu)
{
    if (cpu == NULL)
        return;
    memset(cpu, 0, sizeof(*cpu));
    cpu->current_memory_case = START_ADDRESS;
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
    chip_cpu_t cpu = { 0 };
    int game_on = TRUE;

    init_cpu(&cpu);
    while (game_on) {
        //main_emulate_loop
    }
    return SUCCESS;
}
