/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode OOEE instruction
** Sets the pc to the address at the top of the stack, then subtracts 1 from the stack pointer
*/

#include "emulator/emulate.h"
#include "my_macros.h"

int opcode_00EE(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, UNUSED Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL)
        return FAILURE;
    emulator->cpu->program_counter = emulator->cpu->stack[emulator->cpu->current_stack_address];
    if (emulator->cpu->current_stack_address > 0) {
        emulator->cpu->current_stack_address -= 1;
    }
    return SUCCESS;
}
