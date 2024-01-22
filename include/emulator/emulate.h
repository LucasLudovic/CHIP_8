/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Emulate header
** Header for the emulator mains functions
*/

#ifndef EMULATE_H_
    #define EMULATE_H_
    #include <SFML/Graphics.h>
    #include "my_types.h"
    #define NB_BYTES 4096
    #define STACK_LVL 16
    #define NB_REGISTER 16
    #define START_ADDRESS 0x200
    #define PIXEL_BY_WIDTH 64
    #define PIXEL_BY_HEIGHT 32
    #define NB_OPCODE 35

typedef struct action_s {
    sfEvent event;
    Uint8 key_pressed_value;
} action_t;

typedef struct jump_s {
    Uint16 mask[NB_OPCODE];
    Uint16 id[NB_OPCODE];
} jump_t;

typedef struct screen_s {
    sfRenderWindow *window;
    Uint8 pixels[PIXEL_BY_HEIGHT][PIXEL_BY_WIDTH];
    Uint64 pixel_height;
    Uint64 pixel_width;
} screen_t;

typedef struct chip_cpu_s {
    Uint8 memory[NB_BYTES];
    Uint16 program_counter;
    Uint8 memory_register[NB_REGISTER];
    Uint16 address_register;
    Uint64 stack[STACK_LVL];
    Uint8 current_stack_address;
    Uint16 sys_timer;
    Uint16 sound_timer;
} chip_cpu_t;

typedef struct emulator_s {
    chip_cpu_t *cpu;
    screen_t *screen;
    action_t *action;
} emulator_t;

int emulate_chip_8(void);

#endif
