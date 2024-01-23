/* VALIANCE PROJECT
** 23/01/2024
** Emulator CHIP-8
** Opcode FX55 instructions
** Store V0 through Vx in memory starting at location I
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_FX55(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode FX55\n");
    for (int i = 0; i <= b3; i += 1)
        emulator->cpu->memory[emulator->cpu->address_register + i] = emulator->cpu->memory_register[i];
    return SUCCESS;
}
