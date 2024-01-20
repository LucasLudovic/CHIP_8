/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 3XKK instructions
** Skip next instructions if Vx == kk
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my_macros.h"
#include "my.h"

int opcode_3XKK(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL || emulator->cpu->memory_register == NULL)
        return display_error("Unable to use the cpu with opcode 3xkk");
    if (emulator->cpu->memory_register[b3] == ((b2 << 4) | b1))
        emulator->cpu->program_counter += 2;
    return SUCCESS;
}
