/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode FX65 instructions
** Read V0 through Vx from memory starting at location I
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_FX65(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode FX65\n");
    for (int i = 0; i <= b3; i += 1)
        emulator->cpu->memory_register[i] = emulator->cpu->memory[emulator->cpu->address_register + i];
    return SUCCESS;
}
