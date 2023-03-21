#pragma once
#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace popesq {

	class Swarm
	{
	public:
		const static int NPARTICLES = 5000;
	private:
		Particle* m_pParticles;
		int lastTime;
	public:
		Swarm();
		virtual ~Swarm();
		const Particle* const getParticles() { return m_pParticles; }
		void update(int elapsed);
	};

}

#endif 
