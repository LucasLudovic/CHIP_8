/* VALIANCE PROJECT
** 22/01/2024
** Emulator CHIP-8
** Opcode EX9E instructions
** Skip next instruction if key with value of Vx is pressed
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

int opcode_EX9E(emulator_t *emulator, UNUSED Uint8 b1, UNUSED Uint8 b2, Uint8 b3)
{
    if (emulator == NULL || emulator->cpu == NULL || emulator->action == NULL)
        return display_error("Unable to access CPU for opcode EX9E\n");
    if (emulator->action->key_pressed_value == emulator->cpu->memory_register[b3])
        emulator->cpu->program_counter += 2;
    return SUCCESS;
}
