/*
Basic object classes and method 
definitions for simulation software
File: simul.hpp
Todd King
*/

#include <stream.hpp>
#include <disp.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include "simconst.h"

#define ESC (27)
#define MAX_BODY_POOL (100)

typedef struct VECTOR_2D {
	double x, y;
};

class BODY {
	VECTOR_2D world;
	VECTOR_2D velocity; 
	double mass;
	double gmass;
	char icon;
public:
	BODY();
	set_mass (double m);
	set_velocity (double x, double y); set_position (double x, double y);
	apply_force (VECTOR 2D from, double amount);
	VECTOR_2D position();
	double get_gmass();
	update();
	set_icon (char c);
};

/* Distance and time units are converted to screen units and ticks */
BODY::set_mass (double m) {
	double pow();
	mass = m; 
	gmass = G * m;
};

BODY::set_velocity (double x, double y) {
	velocity.x = x;
	velocity.y = y;
};

BODY::set_position (double x, double y) {
	world.x = x;
	world.y = y;
}

BODY::apply_force (VECTOR_2D from, double gmass) {
	VECTOR_2D d;
	double rs;
	double v;
	double r;
	
	d.x = world.x - from.x;
	d.y = world.y - from.y;
	
	rs = (d.x * d.x) + (d.y * d.y);
	if (rs != 0.0) { // there's a separation
		r = sqrt(rs);
		v = (gmass / rs) * SECS_PER_TIC:
		velocity.x = v * d.x / r;
		velocity.y = v * d.y / r;
	}
};

BODY::BODY() {

	world.x=0;
	world.y = 0;
	velocity.x = 0;
	velocity.y = 0;
	icon = '*';
};

VECTOR_2D BODY::position() {
	VECTOR_2D vec;
	
	vec.x = world.x;
	vec.y = world.y;
	return(vec);
}

double BODY::get_gmass () {
	return (gmass);
}

BODY::set_icon (char c) { icon= c; }

class UNIVERSE {
	unsigned int body_cnt;
	BODY *body_pool [MAX_BODY_POOL];
public:
	UNIVERSE();
	service (BODY *bptr);
	big_bang ();
};

UNIVERSE:: UNIVERSE() (
	body_cnt = 0;
}

UNIVERSE::service (BODY *bptr) {
    if (body_cnt >= MAX_BODY_POOL) return(0); 
    body_pool [body_cnt] = bptr;
    body_cnt++;
};

UNIVERSE::big_bang () {
    int i, j;
    init_screen();
    print_message(" Press ESC to stop.");

    for(;;) {

        print_tick();
        if (kbhit ()) {
             switch (getch())
            {
                case ESC:
                return(0);
            }
        }
        sleep (0.1);
        /* Let each body influence all others */ 
        for (i=0; i < body_cnt; i++) {
            for(j=0; j < body_cnt; j++) {
                if(j == i) continue; // don't apply force to self 
                body_pool [i]->apply_force (body_pool [j]->position(), body_pool [j]->get_gmass());
            }
        }
        /* Display all bodies */
        for (i=0; i < body_cnt; i++) {
            body_pool [i]->update();
        }
    }
    deinit_screen();
};

sleep (double seconds) {
    time_t itimel, ltime2;
    time (&ltimel);
    time (&ltime2);
    while (difftime (ltimel, ltime2) < seconds) {
        time (&ltime2);
    }
}
