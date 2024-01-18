/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode OOE0 instruction
** Clear the display
*/

#include "display/graphics.h"
#include "emulator/emulate.h"
#include "my_macros.h"

int opcode_00E0(emulator_t *emulator)
{
    clear_screen(emulator->screen);
    return SUCCESS;
}
