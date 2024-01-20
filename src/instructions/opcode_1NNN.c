/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 1NNN instruction
** Sets the program counter to NNN
*/

#include "my_types.h"
#include "emulator/emulate.h"
#include "my_macros.h"

int opcode_1NNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    Uint16 address_NNN = (b3 << 8) | (b2 << 4) | b1;

    emulator->cpu->program_counter = address_NNN;
    return SUCCESS;
}
