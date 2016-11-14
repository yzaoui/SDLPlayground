#include "main.h"

#include <iostream>

#include "log_error.h"
#include "res_path.h"

bool init() {
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		logSDLError(std::cout, "SDL_Init");
		return false;
	}

	/* Create Window */
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == nullptr) {
		logSDLError(std::cout, "SDL_CreateWindow");
		return false;
	}

	/* Get Window Surface */
	gScreenSurface = SDL_GetWindowSurface(gWindow);

	return true;
}

bool loadMedia() {
	/* Load Splash Image */
	gImage = loadSurfaceFromBMP(getResourcePath() + "hello_world.bmp");

	if (gImage == nullptr) {
		logError(std::cout, "Failed to load media.");
		return false;
	}

	return true;
}

void close() {
	/* Deallocate Surface */
	SDL_FreeSurface(gImage);
	gImage = nullptr;

	/* Destroy Window */
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	/* Quit SDL Subsystems */
	SDL_Quit();
}

SDL_Surface* loadSurfaceFromBMP(std::string path) {
	//Load image from specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

	if (loadedSurface == nullptr) {
		logSDLError(std::cout, "SDL_LoadBMP");
	}

	return loadedSurface;
}

int main (int argc, char** argv) {
	/******************************
	 * Initialization
	 ******************************/
	if (!init()) {
		logError(std::cout, "Failed to initialize.");
		close();
		return 1;
	}
	/* Load Media */
	if (!loadMedia()) {
		close();
		return 1;
	}

	/******************************
	 * Game Loop
	 ******************************/
	//Main loop flag
	bool quit = false;
	//Main event handler
	SDL_Event event;

	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			//User requests to quit
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}

		//Apply the image
		SDL_BlitSurface(gImage, nullptr, gScreenSurface, nullptr);
		//Update the window surface
		SDL_UpdateWindowSurface(gWindow);
	}

	close();

	return 0;
}
