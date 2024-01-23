/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 4xkk instructions
** Skip next instruction if Vx != kk
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my_macros.h"
#include "my.h"

int opcode_4XKK(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode 4xkk\n");
    if (emulator->cpu->memory_register[b3] != ((b2 << 4) | b1))
        emulator->cpu->program_counter += 2;
    return SUCCESS;
}
