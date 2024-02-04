/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 5XY0 instructions
** Skip next instruction if Vx == Vy
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my_macros.h"
#include "my.h"

int opcode_5XY0(emulator_t *emulator, UNUSED Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode 5xy0\n");
    if (emulator->cpu->memory_register[b3] == emulator->cpu->memory_register[b2])
        emulator->cpu->program_counter += 2;
    return SUCCESS;
}

