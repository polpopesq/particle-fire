#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace popesq
{
	class Screen
	{
	public:
		const static int HEIGHT = 600;
		const static int WIDTH = 800;

	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer1;
		Uint32* m_buffer2;


	public:
		Screen();
		bool init();
		void update();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		bool ProcessEvents();
		void close();
		void boxBlur();
	};
}

#endif