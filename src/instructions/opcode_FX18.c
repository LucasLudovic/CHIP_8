/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode FX18 instructions
** Sound Timer = Vx
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_FX18(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode FX18\n");
    emulator->cpu->sound_timer = emulator->cpu->memory_register[b3];
    return SUCCESS;
}
