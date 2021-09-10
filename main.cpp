#include "window.h"
#include "model.h"
#include <iostream>

using namespace std;

Color white = {0xff, 0xff, 0xff, 0xff};
Color black = {0x00, 0x00, 0x00, 0xff};
Color red = {0xff, 0x00, 0x00, 0xff};
Color green = {0x00, 0xff, 0x00, 0xff};
Color blue = {0x00, 0x00, 0xff, 0xff};


int main(int argc, char *argv[]){

	const int height = 400;
	const int width = 600;

	Window sdl_window;
	sdl_window.createWindow("Sphagetti renderer", width, height);
	sdl_window.createRenderer();

	bool quit = false;
	SDL_Event event;

	//specify filename and scale
	Model model(argv[1], 1);
	model.mesh();

	//main loop
	while(!quit){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
				quit = true;
			}
		}

		//clear the renderer
		sdl_window.renderClear();

		//processing things

		//draw the model's triangles on the screen
		//if you can't see something, make sure that you scale it from Model class constructor
		for(auto tri: model.triangles){

			Triangle t = {
							Vector3((tri.a.x+1.0)*width/2.0, (tri.a.y+1.0)*height/2.0, 0),
							Vector3((tri.b.x+1.0)*width/2.0, (tri.b.y+1.0)*height/2.0, 0),
							Vector3((tri.c.x+1.0)*width/2.0, (tri.c.y+1.0)*height/2.0, 0)
						};

			sdl_window.drawTriangle(t, green);
		}

		//set back the old color
    	sdl_window.setColor(black);

		sdl_window.present();
	}

	sdl_window.quit();

	return 0;
}