/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Main
** Call the program to execute
*/

#include "emulator/emulate.h"
#include "my.h"

int main(int argc, char **argv)
{
    if (argc != 2 || argv == NULL || argv[1] == NULL)
        return display_error("Wrong arguments\n");
    return emulate_chip_8(argv[1]);
}
