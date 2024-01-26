/* VALIANCE PROJECT
** 22/01/2024
** Emulator CHIP-8
** Opcode BNNN instructions
** Jump to NNN + V0
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_BNNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode BNNN\n");
    emulator->cpu->program_counter = ((b3 << 8) | (b2 << 4) | b1) + emulator->cpu->memory_register[0];
    return SUCCESS;
}
