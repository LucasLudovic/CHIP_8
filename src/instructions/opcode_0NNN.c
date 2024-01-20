/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode ONN instruction
** Do nothing in modern computers
*/

#include "emulator/emulate.h"
#include "my_macros.h"

int opcode_0NNN(UNUSED emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, UNUSED Uint8 b3)
{
    return SUCCESS;
}
