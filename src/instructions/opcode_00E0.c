#include "display/graphics.h"
#include "emulator/emulate.h"
#include "my_macros.h"

int opcode_00E0(emulator_t *emulator)
{
    clear_screen(emulator->screen);
    return SUCCESS;
}
