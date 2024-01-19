/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Rom Handler
** Retrieve the instructions binary from the provided rom
*/

#include <stdio.h>
#include "my_macros.h"
#include "emulator/emulate.h"
#include "my.h"

int load_rom(chip_cpu_t *cpu, const char *path)
{
    FILE *rom = fopen(path, "rb");

    if (rom == NULL)
        return display_error("Unable to open the rom\n");
    fread(&cpu->memory[START_ADDRESS], sizeof(char) * (NB_BYTES - START_ADDRESS),
          1, rom);
    fclose(rom);
    return SUCCESS;
}
