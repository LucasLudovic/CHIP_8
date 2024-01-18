#include "my_macros.h"
#include "graphics.h"
#include "emulate.h"

int opcode_00E0(emulator_t *emulator)
{
    clear_screen(emulator->screen);
    return SUCCESS;
}
