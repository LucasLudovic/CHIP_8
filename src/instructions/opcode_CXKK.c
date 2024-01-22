/* VALIANCE PROJECT
** 22/01/2024
** Emulator CHIP-8
** Opcode CXKK instructions
** Vx = (random byte) & kk
*/

#include <stdlib.h>
#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_CXKK(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    int rand_number = 0;

    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode 8XY6\n");
    rand_number = rand() & 0xFF;
    emulator->cpu->memory_register[b3] = rand_number & ((b2 << 4) | b1);
    return SUCCESS;
}
