/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode FX33 instructions
** BCD of Vx in memory I, I +1 and I + 2
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_FX33(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode FX33\n");
    emulator->cpu->memory[emulator->cpu->address_register] = emulator->cpu->memory_register[b3] / 100;
    emulator->cpu->memory[emulator->cpu->address_register + 1] = (emulator->cpu->memory_register[b3] / 10) % 10;
    emulator->cpu->memory[emulator->cpu->address_register + 2] = emulator->cpu->memory_register[b3] % 10;
    return SUCCESS;
}
