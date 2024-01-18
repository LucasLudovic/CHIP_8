#ifndef CPU_H_
    #define CPU_H_
    #include "emulator/emulate.h"
    #define NB_OPCODE 35

typedef struct instructions_s {
    unsigned short id[NB_OPCODE];
    int (*function[NB_OPCODE])(emulator_t *emulator);
}instructions_t;

#endif
