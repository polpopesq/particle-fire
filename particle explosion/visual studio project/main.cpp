#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include <math.h>
#include "Swarm.h"

using namespace std;
using namespace popesq;

int main(int argc, char* argv[])
{

	Screen screen;

	if (!screen.init())
	{
		cout << "Error initialising SDL." << endl;
	}

	Swarm swarm;

	while (true)
	{

		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		const Particle* const pParticles = swarm.getParticles();

		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
		unsigned char red = (unsigned char)((1 + cos(elapsed * 0.002)) * 128);
		unsigned char blue = (unsigned char)((1 + cos(elapsed * 0.003)) * 128);


			for (int i = 0; i < Swarm::NPARTICLES; i++)
		{

			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::WIDTH / 2;
			int y = particle.m_y * Screen::WIDTH / 2 + Screen::HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

			screen.boxBlur();

		screen.update();

		if (!screen.ProcessEvents())
			break;
	}

	screen.close();

	return 0;
}