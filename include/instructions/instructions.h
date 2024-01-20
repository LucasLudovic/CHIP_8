#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_
    #include "emulator/emulate.h"
    #include "my_types.h"

int opcode_00E0(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_00EE(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_0NNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_1NNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_2NNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);

#endif
