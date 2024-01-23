/* VALIANCE PROJECT
** 23/01/2024
** Emulator CHIP-8
** Opcode EXA1 instructions
** Skip next instructions if key with value of Vx not pressed
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_EXA1(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL || emulator->action == NULL)
        return display_error("Unable to access CPU with opcode EXA1\n");
    if (emulator->action->key_pressed_value != emulator->cpu->memory_register[b3])
        emulator->cpu->program_counter += 2;
    return SUCCESS;
}
