/* VALIANCE PROJECT
** 23/01/2024
** Emulator CHIP-8
** Rom header
** Header for loading the rom
*/

#ifndef ROM_H_
    #define ROM_H_

int load_rom(chip_cpu_t *cpu, const char *path);

#endif
