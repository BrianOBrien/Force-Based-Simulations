/* 
Methods which are related to screen I/O. 
File: simulscr.hpp 
Todd King
*/
#include "simconst.h"

#define DISPLAY_Y (24)
#define DISPLAY_X (80)

BODY::update() {
    extern VECTOR_2D Extent;
    VECTOR_2D screen;

    screen.x DISPLAY X (world.x / EXTENT X); 
    screen.y = DISPLAY Y (world.y / EXTENT Y);

    if ( (screen.x < DISPLAY_X && screen.x > 0.0) && (screen.y< DISPLAY_Y && screen.y > 0.0) ) {
        disp_move (DISPLAY_Y (int) screen.y, (int) screen.x);
        disp_printf(" ");
    }

    world.x += velocity.x * SECS_PER_TIC;
    world.y += velocity.y * SECS_PER_TIC;

    screen.x = DISPLAY_X * (world.x / EXTENT_X);
    screen.y = DISPLAY_Y * (world.y / EXTENT_Y);

    if (screen.x < DISPLAY_X && screen.x >= 0.0) && (screen.y < DISPLAY_Y && screen.y > 0.0)) { 
        disp_move (DISPLAY_Y (int) screen.y, (int) screen.x); 
        disp_printf("%c", icon);
    }
    disp_move (0,0);
};

init_screen() {
    disp_open();
    disp_move (0, 0); 
    disp_eeop();
}
deinit_screen() { 
    disp_close();
}
print_tick() {
    static unsigned int Tick = 0;
    disp_move (0, 0);
    disp_printf("Tick: %u", Tick);
    Tick++;
}
print_message (char mesg[]) { 
    disp_move (24,0); 
    disp_printf(mesg);
}
