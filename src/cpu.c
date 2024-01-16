#include "emulate.h"
#include "my.h"

unsigned short get_opcode(chip_cpu_t *cpu)
{
    unsigned short opcode = 0;

    if (cpu == NULL)
        return display_error("Unable to load cpu to read opcode\n");
    opcode = cpu->memory[cpu->program_counter] << 8 | cpu->memory[cpu->program_counter + 1];
    return opcode;
}
