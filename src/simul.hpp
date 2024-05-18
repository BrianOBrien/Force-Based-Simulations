/*
Basic object classes and method 
definitions for simulation software
File: simul.hpp
Todd King
*/

//#include <stream.hpp>
//#include <disp.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include "simconst.h"

#define ESC (27)
#define MAX_BODY_POOL (100)

typedef struct {
	double x, y;
} VECTOR_2D;

class BODY {
	VECTOR_2D world;
	VECTOR_2D velocity; 
	double mass;
	double gmass;
	char icon;
public:
	BODY();
	void set_mass (double m);
	void set_velocity (double x, double y);
	void set_position (double x, double y);
	void apply_force (VECTOR_2D from, double amount);
	VECTOR_2D position();
	double get_gmass();
	void update();
	void set_icon (char c);
};

/* Distance and time units are converted to screen units and ticks */
void BODY::set_mass (double m) {
	double pow();
	mass = m; 
	gmass = G * m;
};
void BODY::set_velocity (double x, double y) {
	velocity.x = x;
	velocity.y = y;
};
void BODY::set_position (double x, double y) {
	world.x = x;
	world.y = y;
};
void BODY::apply_force (VECTOR_2D from, double gmass) {
	VECTOR_2D d;
	double rs;
	double v;
	double r;
	
	d.x = world.x - from.x;
	d.y = world.y - from.y;
	
	rs = (d.x * d.x) + (d.y * d.y);
	if (rs != 0.0) { // there's a separation
		r = sqrt(rs);
		v = (gmass / rs) * SECS_PER_TIC;
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

	gmass = 0.0;
	mass = 0.0;
};
VECTOR_2D BODY::position() {
	VECTOR_2D vec;

	vec.x = world.x;
	vec.y = world.y;
	return(vec);
};
double BODY::get_gmass () {
	return (gmass);
};
void BODY::set_icon (char c) {
	icon = c;
};

void BODY::update () {

}

class UNIVERSE {
	unsigned int body_cnt;
	BODY** body_pool; // [MAX_BODY_POOL] = {};
public:
	UNIVERSE ();
	void service (BODY *bptr);
#ifdef ZORTECH
	void big_bang ();
#endif
	void propagate ();
};

UNIVERSE::UNIVERSE () {
	body_cnt = 0;
	body_pool = new BODY* [MAX_BODY_POOL];
	int i = 0;
	for (i = 0; i < MAX_BODY_POOL; ++i)
		body_pool[i] = new BODY();
};


void UNIVERSE::service (BODY *bptr) {
    if (body_cnt >= MAX_BODY_POOL) return; // was 0?
    body_pool [body_cnt] = bptr;
    body_cnt++;
};

void UNIVERSE::propagate ()
{
	unsigned int i, j;
	/* Let each body influence all others */
	for (i = 0; i < body_cnt; i++) {
		for (j = 0; j < body_cnt; j++) {
			if (j == i) continue; // don't apply force to self 
			body_pool[i]->apply_force(body_pool[j]->position(), body_pool[j]->get_gmass());
		}
	}
	/* Display all bodies */
	for (i = 0; i < body_cnt; i++) {
		body_pool[i]->update();
	}
};
#ifdef ZORTECH
void UNIVERSE::big_bang () {
    init_screen();
    print_message((char *) " Press ESC to stop.");

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
		propagate();
    }
    deinit_screen();
};
#endif

#ifdef ZORTECH
void sleep (double seconds) {
    time_t ltimel, ltime2;
    time (&ltimel);
    time (&ltime2);
    while (difftime (ltimel, ltime2) < seconds) {
        time (&ltime2);
    }
}
#endif
