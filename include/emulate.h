#ifndef EMULATE_H_
    #define EMULATE_H_
    #define NB_BYTES 4096
    #define STACK_LVL 16
    #define NB_REGISTER 16
    #define START_ADDRESS 0x200

typedef struct chip_cpu_s {
    unsigned char memory[NB_BYTES];
    unsigned short current_memory_case;
    unsigned long memory_register[NB_REGISTER];
    unsigned short address_register;
    unsigned long stack[STACK_LVL];
    unsigned char current_stack_address;
    unsigned short sys_timer;
    unsigned short sound_timer;
}chip_cpu_t;

int emulate_chip_8(void);

#endif
