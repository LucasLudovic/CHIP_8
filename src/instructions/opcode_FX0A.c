/* VALIANCE PROJECT
** 23/01/2024
** Emulator CHIP-8
** Opcode FX0A instructions
** Wait for a key pressed, then value put in Vx
*/

#include <stdio.h>
#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"
#include "input/events.h"

static
void get_event(emulator_t *emulator)
{
    sfRenderWindow_waitEvent(emulator->screen->window, &emulator->action->event);
}

int opcode_FX0A(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL || emulator->action == NULL)
        return display_error("Unable to access CPU with opcode FX0A\n");
    get_event(emulator);
    emulator->cpu->memory_register[b3] = emulator->action->key_pressed_value;
    return SUCCESS;
}
