/* 
Methods which are related to screen I/O. 
File: simulscr.hpp 
Todd King
*/
#include "simul.hpp"
#include "simconst.h"

#define DISPLAY_Y (24)
#define DISPLAY_X (80)

void BODY::update() {
    //VECTOR_2D Extent;
    VECTOR_2D screen;

    screen.x = DISPLAY_X * (world.x / EXTENT_X); 
    screen.y = DISPLAY_Y * (world.y / EXTENT_Y);

    if ( (screen.x < DISPLAY_X && screen.x > 0.0) && 
         (screen.y < DISPLAY_Y && screen.y > 0.0) ) {
#ifdef ZORTECH
        disp_move (DISPLAY_Y - (int) screen.y, (int) screen.x);
        disp_printf(" ");
#endif
    }

    world.x += velocity.x * SECS_PER_TIC;
    world.y += velocity.y * SECS_PER_TIC;

    screen.x = DISPLAY_X * (world.x / EXTENT_X);
    screen.y = DISPLAY_Y * (world.y / EXTENT_Y);

    if ( (screen.x < DISPLAY_X && screen.x >= 0.0) && 
         (screen.y < DISPLAY_Y && screen.y > 0.0)) {
#ifdef ZORTECH
        disp_move (DISPLAY_Y - (int) screen.y, (int) screen.x); 
        disp_printf("%c", icon);
#endif
    }
#ifdef ZORTECH
    disp_move (0,0);
#endif
};

void init_screen(void) {
#ifdef ZORTECH
    disp_open();
    disp_move (0, 0); 
    disp_eeop();
#endif
}
void deinit_screen(void) { 
#ifdef ZORTECH
    disp_close();
#endif
}
void print_tick(void) {
    static unsigned int Tick = 0;
#ifdef ZORTECH
    disp_move (0, 0);
    disp_printf("Tick: %u", Tick);
#endif
    Tick++;
}
void print_message (char mesg[]) {
#ifdef ZORTECH
    disp_move (24,0); 
    disp_printf(mesg);
#endif
}
