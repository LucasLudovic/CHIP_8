/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Jump_table header
** Structs for the jump table
*/

#ifndef JUMP_TABLE_H_
    #define JUMP_TABLE_H_
    #include "emulator/emulate.h"

static const jump_t jump_table = { .mask[0] = 0xFFFF, .id[0] = 0x00E0,    // OOEO
        .mask[1] = 0xFFFF, .id[1] = 0x00EE,    // OOEE
        .mask[2] = 0x0000, .id[2] = 0x0FFF,    // 0NNN
        .mask[3] = 0xF000, .id[3] = 0x1000,    // 1NNN
        .mask[4] = 0xF000, .id[4] = 0x2000,    // 2NNN
        .mask[5] = 0xF000, .id[5] = 0x3000,    // 3xkk
        .mask[6] = 0xF000, .id[6] = 0x4000,    // 4xkk
        .mask[7] = 0xF00F, .id[7] = 0x5000,    // 5xy0
        .mask[8] = 0xF000, .id[8] = 0x6000,    // 6xkk
        .mask[9] = 0xF000, .id[9] = 0x7000,    // 7xkk
        .mask[10] = 0xF00F, .id[10] = 0x8000,  // 8xy0
        .mask[11] = 0xF00F, .id[11] = 0x8001,  // 8xy1
        .mask[12] = 0xF00F, .id[12] = 0x8002,  // 8xy2
        .mask[13] = 0xF00F, .id[13] = 0x8003,  // 8xy3
        .mask[14] = 0xF00F, .id[14] = 0x8004,  // 8xy4
        .mask[15] = 0xF00F, .id[15] = 0x8005,  // 8xy5
        .mask[16] = 0xF00F, .id[16] = 0x8006,  // 8xy6
        .mask[17] = 0xF00F, .id[17] = 0x8007,  // 8xy7
        .mask[18] = 0xF00F, .id[18] = 0x800E,  // 8xyE
        .mask[19] = 0xF00F, .id[19] = 0x9000,  // 9xy0
        .mask[20] = 0xF000, .id[20] = 0xA000,  // Annn
        .mask[21] = 0xF000, .id[21] = 0xB000,  // Bnnn
        .mask[22] = 0xF000, .id[22] = 0xC000,  // Cxkk
        .mask[23] = 0xF000, .id[23] = 0xD000,  // Dxyn
        .mask[24] = 0xF0FF, .id[24] = 0xE09E,  // Ex9E
        .mask[25] = 0xF0FF, .id[25] = 0xE0A1,  // ExA1
        .mask[26] = 0xF0FF, .id[26] = 0xF007,  // Fx07
        .mask[27] = 0xF0FF, .id[27] = 0xF00A,  // Fx0A
        .mask[28] = 0xF0FF, .id[28] = 0xF015,  // Fx15
        .mask[29] = 0xF0FF, .id[29] = 0xF018,  // Fx18
        .mask[30] = 0xF0FF, .id[30] = 0xF01E,  // Fx1E
        .mask[31] = 0xF0FF, .id[31] = 0xF029,  // Fx29
        .mask[32] = 0xF0FF, .id[32] = 0xF033,  // Fx33
        .mask[33] = 0xF0FF, .id[33] = 0xF055,  // Fx55
        .mask[34] = 0xF0FF, .id[34] = 0xF065,  // Fx65
};

static const instructions_t instructions = {
        .id[0] = 0x00E0, .function[0] = &opcode_00E0,
        .id[1] = 0x00EE,
        .id[2] = 0x0FFF,
        .id[3] = 0x1000,
        .id[4] = 0x2000,
        .id[5] = 0x3000,
        .id[6] = 0x4000,
        .id[7] = 0x5000,
        .id[8] = 0x6000,
        .id[9] = 0x7000,
        .id[10] = 0x8000,
        .id[11] = 0x8001,
        .id[12] = 0x8002,
        .id[13] = 0x8003,
        .id[14] = 0x8004,
        .id[15] = 0x8005,
        .id[16] = 0x8006,
        .id[17] = 0x8007,
        .id[18] = 0x800E,
        .id[19] = 0x9000,
        .id[20] = 0xA000,
        .id[21] = 0xB000,
        .id[22] = 0xC000,
        .id[23] = 0xD000,
        .id[24] = 0xE09E,
        .id[25] = 0xE0A1,
        .id[26] = 0xF007,
        .id[27] = 0xF00A,
        .id[28] = 0xF015,
        .id[29] = 0xF018,
        .id[30] = 0xF01E,
        .id[31] = 0xF029,
        .id[32] = 0xF033,
        .id[33] = 0xF055,
        .id[34] = 0xF065,
};

#endif
