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
If you want to run flyingBirds with your own parameters first you have to write in your terminal:

	$ cd flyingbirds

Then:

	$ make clean
	
Then:

	$ make

And finally:

	$ ./bin/FlyingBirds.run -N 100 -s 0.6 -c 0.2 -a 0.2

Where:

N: Number of birds.

s: Separation weight.

c: Cohesion weight.

a: Alignment weight.

and:

Wc+Wa+Ws = 1

Ways of bird working:
=====================================
There are two ways for the birds working:

First one is:

Using min function as Professor Rannou said that is:

	double *Math::min(double x, double y, double scalar)
	{	
  		double vector[2];

  		double module = sqrt(pow(x,2)+pow(y,2));

  		if (module > Vmax){
    		vector[0] = (x/module) * Vmax;
    		vector[1] = (y/module) * Vmax;
  		}
  		else
  		{
    		vector[0] = x;
    		vector[1] = y;
  		}

  		return vector;

	}

To work with this way you have to:

- Uncomment line 168 in Math.cpp

- Comment line 169 in Math.cpp

- Uncomment line 244 in Bird.cpp

- Comment line 246 in Bird.cpp

- Uncomment lines 248 & 249 in Bird.cpp

The second way is work with the original function, that is:

	void Math::minV1(double Vx, double Vy, double scalar)
	{
    	if(abs(Vx) >= scalar){
      		if(Vx < 0){
        		Vx = -scalar;
      	}else{
        	Vx = scalar;
     	 	}
    	}

    	if(abs(Vy) >= scalar){
      		if(Vy < 0){
        		Vy = -scalar;
      	}else{
        	Vy = scalar;
      		}
    	}
	}

	double *Math::minV2(double *vector, double scalar)
	{
  		int sizeofvector = sizeof(vector)/sizeof(vector[0]);
  		for(int i=0; i<=sizeofvector; i++){
    		if(abs(vector[i]) >= scalar){
      			if(vector[i] < 0)
        			vector[i]=-scalar;
      			else
        			vector[i]=scalar;
   		 	}
  		}
  		return vector;
	}

To work with this way you have to:

- Comment line 168 in Math.cpp

- Uncomment line 169 in Math.cpp

- Comment line 244 in Bird.cpp

- Uncomment line 246 in Bird.cpp

- Comment lines 248 & 249 in Bird.cpp


Code by:
======================================
Miguel Cárcamo Vásquez.

Daniel Wladdimiro Cottet.