#ifndef CPU_H_
    #define CPU_H_
    #include "emulate.h"

typedef struct instructions_s {
    unsigned short id;
    int (*function)[35];
}instructions_t;

#endif
