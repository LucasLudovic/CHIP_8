#ifndef EMULATE_H_
    #define EMULATE_H_
    #include <SFML/Graphics.h>
    #define NB_BYTES 4096
    #define STACK_LVL 16
    #define NB_REGISTER 16
    #define START_ADDRESS 0x200
    #define PIXEL_BY_WIDTH 64
    #define PIXEL_BY_HEIGHT 32

typedef struct screen_s {
    sfRenderWindow *window;
    unsigned char pixels[PIXEL_BY_HEIGHT][PIXEL_BY_WIDTH];
    unsigned long long pixel_height;
    unsigned long long pixel_width;
}screen_t;

typedef struct chip_cpu_s {
    unsigned char memory[NB_BYTES];
    unsigned short program_counter;
    unsigned long memory_register[NB_REGISTER];
    unsigned short address_register;
    unsigned long stack[STACK_LVL];
    unsigned char current_stack_address;
    unsigned short sys_timer;
    unsigned short sound_timer;
}chip_cpu_t;

typedef struct emulator_s {
    chip_cpu_t *cpu;
    screen_t *screen;
    sfEvent event;
} emulator_t;

int emulate_chip_8(void);

#endif
