/* VALIANCE PROJECT
** 23/01/2024
** Emulator CHIP-8
** Opcode FX07 instructions
** Set Vx = delay_timer value
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_FX07(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode FX07\n");
    emulator->cpu->memory_register[b3] = emulator->cpu->sys_timer;
    return SUCCESS;
}
