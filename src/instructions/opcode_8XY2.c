/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 8XY2 instructions
** Set Vx = Vx & Vy
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_8XY2(emulator_t *emulator, UNUSED Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access the CPU for opcode 8XY2\n");
    emulator->cpu->memory_register[b3] = emulator->cpu->memory_register[b3] & emulator->cpu->memory_register[b2];
    return SUCCESS;
}
