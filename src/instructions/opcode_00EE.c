/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode OOEE instruction
** Sets the pc to the address at the top of the stack, then subtracts 1 from the stack pointer
*/

#include "emulator/emulate.h"
#include "my_macros.h"

int opcode_OOEE(emulator_t *emulator)
{
    emulator->cpu->program_counter = emulator->cpu->stack[STACK_LVL - 1];
    if (emulator->cpu->current_stack_address > 0)
        emulator->cpu->current_stack_address -= 1;
    else
        emulator->cpu->current_stack_address = STACK_LVL - 1;
    return SUCCESS;
}
