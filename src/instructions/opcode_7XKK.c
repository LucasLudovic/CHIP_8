/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 7xkk instructions
** Vx = Vx + kk
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_7XKK(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access the CPU for opcode 7XKK\n");
    emulator->cpu->memory_register[b3] = emulator->cpu->memory_register[b3] + ((b2 << 4) | b1);
    return SUCCESS;
}
