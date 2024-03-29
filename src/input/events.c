/* VALIANCE PROJECT
** 18/01/2024
** Emulator CHIP-8
** Events
** Handle the input functions for the games
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "emulator/emulate.h"
#include "input/events.h"

static
void trigger_action(sfEvent *event)
{
    printf("Key : %i\n", event->key.code);
}

void check_event(emulator_t *emulator)
{
    while (sfRenderWindow_pollEvent(emulator->screen->window, &emulator->event)) {
        switch (emulator->event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(emulator->screen->window);
                break;
            case sfEvtKeyReleased:
                trigger_action(&emulator->event);
                break;
            default:
                break;
        }
    }
}
