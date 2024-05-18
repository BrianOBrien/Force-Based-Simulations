# Force-Based-Simulations
From DrDobbs journal Sept 1989, my introduction to C++ then.
Force-based Simulations.


C++ makes it easy to find out how one body in a universe influences all others.

You have probably heard it said that the languages that best model the real world are object-oriented. When you try to build a simulation system you realize just how true this is. 
This article presents a force-based simulation system written in Zortech's C++ that demonstrates how and why an object-oriented language like C++ is a natural choice for implementing simulation systems.
The most common type of simulation systems is probably circuit type simulations, where components have inputs and perform transformation of the input into some form of output. The output is then fed to another component. With force-based systems, you have a collection of bodies that forms a universe. Each body exerts a force on every other body in the universe. This means that just the presence of a body has an influence on all other bodies. This is significantly different from circuit-based simulation, where influences are channeled from component to component.
Todd is a programmer/analyst with the Institute of Geophysics and Planetary Physics at UCLA. He is also associated with the NASA/JPL Planetary Data Systems project.
Todd can be reached at 1104 N Orchard, Burbank, CA 91506. 
Building a Forced-based System is probably the most difficult and critical element in a simulation system is managing the objects that exist in the simulation. The function of the object manager is to maintain the communication between bodies and to enforce the physical laws. 
Listing One, page 94, contains the source code for the administrator for the system presented in this article. In this listing, the administrator method is called big_bang( ), of the object class UNIVERSE.
 
It is crucial to maintain the integrity of each body. In C++, this is best accomplished by making the physical parameters private and providing methods to return the physical parameters. Because the physical parameters for any body in the system are the same, the class for bodies is called BODY (also in Listing One). The method UNIVERSE: service() registers a body with the UNIVERSE. The collection of bodies to be serviced is maintained as an array of objects of class BODY, and is repeatedly stepped through when you call UNIVERSE: :big_bang( ) In the class of BODY, the most notable method is apply _ force ( ), which takes an outside influence on the body and converts it into a change in physical parameters. The physical law that determines how bodies influence each other is encoded in this method. In the present system, we are using the derivative of the force law of gravity, which results in an instantaneous velocity vector. This velocity vector is then applied to the body’s current velocity vector to determine its new vector. The other member functions of the BODY class are simple, and I will refer you to the source for details.
Viewing the results of the simulations can be done in a variety of ways. In some cases, a table of numbers is sufficient, but in most cases the results are best seen in some animated form. 
Listing Two, page 94, contains those methods and functions that are directly related to the display of a simulation. The method BODY::update( ) displays a body on the screen. It also updates the position of the body based on its velocity vector. Even though I choose to display things as characters (so everyone can watch the simulation), it should be relatively easy to alter the code to work with graphic images.

Simulating the Earth and Moon

Let us look at some examples. Example 1 is a simulation of the Earth and Moon. The source is straight forward. We create the bodies, define their physical parameters (mass, location, and velocity), and then let the UNIVERSE take care of the rest. The numbers used in all the methods are real. So, if the physical laws on which the system is built match reality, the Moon should orbit the earth every 27.3 days. In the example, one day is equal to one tick.
Another thing you will observe when you run this example is that the Earth/Moon pair moves gradually to the left.  While trying to understand this result, I realized that the simulation system had revealed the notion of "center of" Simulates the orbital dynamics of the Earth and Moon.

Todd King 
main() 
{
	BODY earth;
	BODY moon;
	UNIVERSE universe;

	earth.set_mass(5.98;24); 
	earth.set_position(5.0e8, 5.0e8);
	earth.set_icon('E'); 

	moon.set_mass(7.36e22); 
	moon.setPosition(5.0e8, 8.8e8);
	moon.set_icon('M');
	moon.set_velocity(-1020.0, 0.0);

	universe.service(earth);
	universe.service(moon);
	universe.big_bang();
}
Example 1: Simulation of the Earth and the Moon 


mass for systems, even though this notion was not bred into the system. The center of mass for a system is the point that two (or more) orbiting bodies revolve around. It is this point that moves at the velocity of the system as a whole. So, when the Moon was given its initial velocity, the center of mass was given the same velocity. Hence the entire system moves to the left. Figure 1 illustrates this system. Example 1 is a verification-type simulation that demonstrates that the simulation system produces substantiated results. This allows us to perform a hypothetical simulation and trust the results. Let's look at what would happen if Planet X passed through our system. Assume that the planet is twice as big as the Moon. Listing Three, page 96, is the source for this simulation. The system is the same as that presented in Example 1, with the addition of a third body that moves through the system from the lower-left corner to the upper-right corner. When running this example, you will see just how disruptive such an occurrence would be, even if Planet X doesn't collide with any other body. Figure 2 shows the path of Planet X through the Earth/Moon system.

Figure 1: Physical components of the Earth/Moon system. Vi is the initial velocity given to the Moon.


Conclusions 
Simulation systems have broader applications than the model presented here. They are useful in developing and testing new theories. With simulation systems you can change the physical laws and constants and observe the results. One such constant is G, the gravitational constant, which can be found in Listing Four, page 96. Simulations also allow us to duplicate events in nature at a faster rate. For example, it takes the moon a lot less than 27.3 days of wall clock time to revolve about the earth in Example 1.
Games are a form of simulation systems, and with a little work you can create a game with this simulation system by adding a spaceship body to one of the examples and allowing the user to control the rockets on it. The goal would be to obtain an orbit about one of the other bodies. Such a skill could be useful as we begin to move off the surface of our planet.

The system presented here has a few limitations. First, the maximum distance allowed between any two objects is the square root of the largest possible value for a double. On a PC, this value is 1.3el54. Next, the number of bodies that can exist in a UNIVERSE are limited. This is set with the parameter MAXJSODIES and has an upper boundary that is the same as for an int, and is limited because we use an array to track the bodies. Converting this to a link list would eliminate this limitation. 

Bibliography 

Rusnick, Robert, and Halliday, David.
Physics, Part 1. New York: John Wiley & Sons, 1977.
Negoita, Constantin Virgil, and Ralescu, Dan. Simulation, Knowledge-Based Computing and Fuzzy Statistics. New York: Van Nostrand Reinhold Company, Inc., 1987.
Availability
All source code for articles in this issue is available on a single disk. To order, send $14.95 (Calif, residents add sales tax) to Dr. Dobb's Journal, 501 Galveston Dr., Redwood City, CA 94063, or call 800-356-2002 (from inside Calif.) or 800-533-4372 (from outside Calif.).
Please specify the issue number and format (MS-DOS, Macintosh, Kaypro).



![image](https://github.com/BrianOBrien/Force-Based-Simulations/assets/2880825/78b873e2-9ce9-47ea-a81b-ca39256456fe)


![image](https://github.com/BrianOBrien/Force-Based-Simulations/assets/2880825/f4c5c5b7-fe15-4627-afbc-d1aa342a3ac7)




