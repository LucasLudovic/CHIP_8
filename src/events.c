#include <SFML/Graphics.h>
#include <stdio.h>
#include "emulate.h"
#include "events.h"

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
