#ifndef CPU_H_
    #define CPU_H_
    #include "emulator/emulate.h"

typedef struct instructions_s {
    unsigned short id[35];
    int (*function[35])(emulator_t *emulator);
}instructions_t;

#endif
