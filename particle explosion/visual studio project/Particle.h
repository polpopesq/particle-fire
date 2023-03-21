#pragma once
#ifndef PARTICLE_H
#define PARTICLE_H

namespace popesq {

	struct Particle
	{
		double m_x;
		double m_y;

		double m_speed;
		double m_direction;

		Particle();
		virtual ~Particle();
		void update(int interval);

		void init();
	};
}

#endif 