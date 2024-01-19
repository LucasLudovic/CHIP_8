/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** CPU header
** Header to handle the cpu simulator functions
*/

#ifndef CPU_H_
    #define CPU_H_
    #include "emulator/emulate.h"
    #define NB_OPCODE 35

typedef struct instructions_s {
    unsigned short id[NB_OPCODE];
    int (*function[NB_OPCODE])(emulator_t *emulator);
}instructions_t;

#endif
