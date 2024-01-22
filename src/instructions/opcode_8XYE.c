/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 8XYE instructions
** Set Vx = Vx SHL1
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_8XYE(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, UNUSED Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode 8XYE\n");
    emulator->cpu->memory_register[NB_REGISTER - 1] = (emulator->cpu->memory_register[b3] & 0x80) > 0;
    emulator->cpu->memory_register[b3] = emulator->cpu->memory_register[b3] << 1;
    return SUCCESS;
}
