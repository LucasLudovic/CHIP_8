/* VALIANCE PROJECT
** 20/01/2024
** Emulator CHIP-8
** Opcode 8XY0 instructions
** Set Vx = Vy
*/

#include "emulator/emulate.h"
#include "my_macros.h"
#include "my.h"
#include "my_types.h"

int opcode_8XY0(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, UNUSED Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access the cpu with opcode 8XY0\n");
    emulator->cpu->memory_register[b3] = emulator->cpu->memory_register[b2];
    return SUCCESS;
}
