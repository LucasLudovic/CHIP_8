#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_
    #include "emulator/emulate.h"
    #include "my_types.h"

int opcode_00E0(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_00EE(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_0NNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_1NNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_2NNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_3XKK(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_4XKK(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_5XY0(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_6XKK(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_7XKK(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_8XY0(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_8XY1(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_8XY2(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_8XY3(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_8XY4(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_8XY5(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_8XY6(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_8XY7(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_8XYE(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_9XY0(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_ANNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_BNNN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_CXKK(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_DXYN(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_EX9E(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_EXA1(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_FX0A(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_FX1E(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_FX07(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_FX15(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_FX18(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_FX29(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_FX33(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_FX55(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);
int opcode_FX65(emulator_t *emulator, Uint8 b1, Uint8 b2, Uint8 b3);

#endif
