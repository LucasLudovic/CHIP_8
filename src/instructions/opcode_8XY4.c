/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 8XY4 instructions
** Set Vx = Vx + Vy, set Vf = 1 if Vx + Vy > 8 bits
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_8XY4(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    Uint16 added_value = 0;

    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access the CPU for opcode 8XY4\n");
    added_value = emulator->cpu->memory_register[b3] + emulator->cpu->memory_register[b2];
    emulator->cpu->memory_register[NB_REGISTER - 1] = (added_value > 255) ? 1 : 0;
    emulator->cpu->memory_register[b3] += emulator->cpu->memory_register[b2];
    return SUCCESS;
}
