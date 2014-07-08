Flying Birds
===========

Flying birds Simulation using uC++ and openGL

Before make, make sure you have uC++ installed as well as OpenGL

Installing uC++
===============

In the folder uC++ execute file u++-6.0.0.sh

	$ sudo sh u++-6.0.0.sh -p /opt -c /usr/local/bin

Installing OpenGL and G++
==================
	$ sudo apt-get install freeglut3
	$ sudo apt-get install freeglut3-dev 
	$ sudo apt-get install binutils-gold
	$ sudo apt-get install g++
	$ sudo apt-get install g++ cmake
	$ sudo apt-get install libglew-dev
	$ sudo apt-get install mesa-common-dev
	$ sudo apt-get install libglew1.5-dev libglm-dev

Done tasks
==================
- [x] Drawing birds
	- [x] Triangle base 1.0 and 2.0 sides
	- [x] Not random direction
	- [x] Travel max speed
	- [x] Travel max force
	- [x] Travel acceleration
 	- [x] Weights
 	- [x] Birds toroid
- [x] Bird class
- [x] Make world 640x640
- [x] Separate, alineate and cohesionate birds.
- [x] Apply forces
- [x] Give a random position to 'em without srand() 
- [x] Give a random direction to 'em between [0, 2*pi] without srand()
- [x] Bug for distance toroid
- [x] Rotation bird about velocity

Compiling
==================
	$ make flying

Instructions
========================
If you want to run flying with your own parameters first you have to write in your terminal:

	$ make

Then:

	$ ./bin/FlyingBirds.run -N 100 -s 0.6 -c 0.2 -a 0.2

Where:

N: Number of birds,
s: Separation weight.
c: Cohesion weight.
a: Alignment weight.

and:

Wc+Wa+Ws = 1


Code by:
======================================
Miguel Cárcamo Vásquez.

Daniel Wladdimiro Cottet.