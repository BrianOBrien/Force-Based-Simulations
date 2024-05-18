main() 
{
	BODY  earth;
	BODY  moon;
	UNIVERSE universe;
	earth.set_mass (5. 98;24) ; 
	earth.set_position(5.0e8, 5.0e8);
	earth.set_icon('E'); 
	moon.set_mass (7.36e22) ; 
	moon.setPosition(5.0e8, 8.8e8);
	moon.set_icon  I'M');
	moon.set_velocity (-1020.0, 0.0);
	universe.service(earth);
	universe.service(moon);
	universe.big_bang();
}
