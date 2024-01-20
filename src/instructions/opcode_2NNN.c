/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Opcode 2NNN instruction
** Increment stack pointer, set top of the stack to current pc, then pc set to NNN
*/

#include "my_types.h"
#include "emulator/emulate.h"
#include "my_macros.h"
#include "my.h"

int opcode_2NNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL || emulator->cpu->stack == NULL)
        return display_error("Unable to access the cpu\n");
    emulator->cpu->current_stack_address += 1;
    if (emulator->cpu->current_stack_address >= STACK_LVL)
        return display_error("Stack overflow");
    emulator->cpu->stack[emulator->cpu->current_stack_address] = emulator->cpu->program_counter;
    emulator->cpu->program_counter = (b3 << 8) | (b2 << 4) | b1;
    return SUCCESS;
}
