/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 9XY0 instructions
** If Vx != Vy : pc += 2
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_9XY0(emulator_t *emulator, UNUSED Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode 9XY0\n");
    if (emulator->cpu->memory_register[b3] != emulator->cpu->memory_register[b2])
        emulator->cpu->program_counter += 2;
    return SUCCESS;
}
