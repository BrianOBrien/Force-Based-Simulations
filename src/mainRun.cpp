/*
Simulation of what would happen if a planet 
about twice the size of the Moon passed 
close to the earth within the Moon's orbit. 
Todd King
*/

#include "simul.hpp"
#include "simulscr.hpp"
/// <summary>
/// This was main in the days of DOS and Zortech C++
/// I want to make this the 'run' of a thread.
/// </summary>
void Start() {

    BODY earth;
    BODY moon;
    BODY planet_x;
    UNIVERSE universe;

    earth.set_mass (5.98e24);
    earth.set_position (5.0e8, 5.0e8);
    earth.set_icon ('E');

    moon.set_mass (7.36e22);
    moon.set_position (5.0e8, 8.8e8);
    moon.set_icon ('M');
    moon.set_velocity (-1020.0, 0.0);
    
    planet_x.set_mass (14.8e22);
    planet_x.set_position (1.0, 1.0e4); 
    planet_x.set_icon ('X'); 
    planet_x.set_velocity (1800, 2000);

    universe.service(&earth);
    universe.service(&moon);
    universe.service(&planet_x);

    universe.big_bang();
}
