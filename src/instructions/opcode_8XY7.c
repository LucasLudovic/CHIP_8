/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 8XY7 instructions
** Set Vx = Vy - Vx, set VF = NOT borrow
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_8XY7(emulator_t *emulator, UNUSED Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode 8XY7\n");
    emulator->cpu->memory_register[NB_REGISTER - 1] = emulator->cpu->memory_register[b2] > emulator->cpu->memory_register[b3];
    emulator->cpu->memory_register[b3] = emulator->cpu->memory_register[b2] - emulator->cpu->memory_register[b3];
    return SUCCESS;
}
