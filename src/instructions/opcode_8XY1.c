/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 8xy1 instructions
** Set Vx = Vx | Vy
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_8XY1(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU for opcode 8XY1");
    emulator->cpu->memory_register[b3] = (emulator->cpu->memory_register[b3]) | emulator->cpu->memory_register[b2];
    return SUCCESS;
}
