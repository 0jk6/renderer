#include "window.h"
#include <iostream>

using namespace std;

Window::Window(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "SDL Init failed\n";
	}
}

int Window::createWindow(const char *title, int width, int height){
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if(window == nullptr){
		cout << "Cannot create window\n";
		SDL_Quit();
		return 1;
	}
	return 0;
}

int Window::createRenderer(){
	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_SOFTWARE);
	if(renderer == nullptr){
		cout << "Cannot create renderer\n";
		return 1;
	}
	return 0;
}

void Window::renderClear(){
	SDL_RenderClear(renderer);
}

void Window::drawPoint(int x, int y){
	SDL_RenderDrawPoint(renderer, x, y);
}

void Window::setColor(Color color){
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Window::present(){
	SDL_RenderPresent(renderer);
}

//bresenham's line drawing algorithm, credits to https://github.com/ssloy
void Window::line(int x0, int y0, int x1, int y1, Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	//if you are lazy, use the following in built sdl function to draw a line
	//SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
	
	//this block of code will draw lines using bresenham's line drawing algorithm
	bool steep = false; 
    if (std::abs(x0-x1)<std::abs(y0-y1)) { 
        std::swap(x0, y0); 
        std::swap(x1, y1); 
        steep = true; 
    } 
    if (x0>x1) { 
        std::swap(x0, x1); 
        std::swap(y0, y1); 
    } 
    int dx = x1-x0; 
    int dy = y1-y0; 
    int derror2 = std::abs(dy)*2; 
    int error2 = 0; 
    int y = y0; 
    for (int x=x0; x<=x1; x++) { 
        if (steep) { 
            drawPoint(y, x);
        } else { 
        	drawPoint(x, y);
        } 
        error2 += derror2; 
        if (error2 > dx) { 
            y += (y1>y0?1:-1); 
            error2 -= dx*2; 
        } 
    }
}

void Window::drawLine(Point p1, Point p2, Color color){
	line(p1.x, p1.y, p2.x, p2.y, color);
}

void Window::drawTriangle(Triangle tri, Color color){
	line(tri.a.x, tri.a.y, tri.b.x, tri.b.y, color);
	line(tri.b.x, tri.b.y, tri.c.x, tri.c.y, color);
	line(tri.c.x, tri.c.y, tri.a.x, tri.a.y, color);
}


void Window::quit(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}