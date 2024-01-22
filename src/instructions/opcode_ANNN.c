/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode ANNN instructions
** Set I to NNN
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_ANNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode 8XY6\n");
    emulator->cpu->address_register = (b3 << 8) | (b2 << 4) | b1;
    return SUCCESS;
}
