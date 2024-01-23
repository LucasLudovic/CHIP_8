/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** CPU
** Simulate the cpu from the console
*/

#include "emulator/emulate.h"
#include "emulator/cpu.h"
#include "instructions/instructions.h"
#include "my.h"
#include "my_macros.h"
#include "my_types.h"
#include "instructions/jump_table.h"

static
Uint16 get_opcode(chip_cpu_t *cpu)
{
    Uint16 opcode = 0;

    if (cpu == NULL)
        return display_error("Unable to load cpu to read opcode\n");
    opcode = cpu->memory[cpu->program_counter] << 8 | cpu->memory[cpu->program_counter + 1];
    return opcode;
}

static
Uint8 get_action(Uint16 opcode)
{
    for (size_t i = 0; i < NB_OPCODE; i += 1) {
        if ((jump_table.mask[i] & opcode) == jump_table.id[i])
            return i;
    }
    display_error("Unable to find the opcode\n");
    return SUCCESS;
}

void interpret(emulator_t *emulator)
{
    Uint16 opcode = get_opcode(emulator->cpu);
    Uint8 b1 = 0;
    Uint8 b2 = 0;
    Uint8 b3 = 0;
    Uint8 action = 0;

    b1 = (opcode & 0x000F);
    b2 = (opcode & 0x00F0) >> 4;
    b3 = (opcode & 0x0F00) >> 8;
    action = get_action(opcode);
    for (int i = 0; i < NB_OPCODE; i += 1) {
        if (instructions.id[i] == jump_table.id[action]) {
            instructions.function[i](emulator, b1, b2, b3);
            break;
        }
    }
    emulator->cpu->program_counter += 2;
}
