/* VALIANCE PROJECT
** 22/01/2024
** Emulator CHIP-8
** Opcode DXYN instructions
** Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision.
*/

#include "emulator/emulate.h"
#include "my_types.h"
#include "my.h"
#include "my_macros.h"

static
void change_pixel(emulator_t *emulator, const Uint16 codage,
                  const Uint8 j, const Uint8 pos_x, const Uint8 pos_y)
{
    if (pos_y < PIXEL_BY_HEIGHT && pos_x < PIXEL_BY_WIDTH && ((codage << j) & 0x80)) {
        if (emulator->screen->pixels[pos_y][pos_x] == TRUE)
            emulator->cpu->memory_register[NB_REGISTER - 1] = 1;
        emulator->screen->pixels[pos_y][pos_x] = !emulator->screen->pixels[pos_y][pos_x];
    }
}

int opcode_DXYN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3)
{
    Uint8 pos_y = 0;
    Uint8 pos_x = 0;
    Uint16 codage = 0;

    if (emulator == NULL || emulator->cpu == NULL)
        return display_error("Unable to access CPU with opcode DXYN\n");
    emulator->cpu->memory_register[NB_REGISTER - 1] = 0;
    for (Uint8 i = 0; i < b1; i += 1) {
        codage = emulator->cpu->memory[emulator->cpu->address_register + i];
        pos_y = emulator->cpu->memory_register[b2] + i;
        for (Uint8 j = 0; j < 8; j += 1) {
            pos_x = emulator->cpu->memory_register[b3] + j;
            change_pixel(emulator, codage, j, pos_x, pos_y);
        }
    }
    return SUCCESS;
}
