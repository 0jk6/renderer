#pragma once

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL2/SDL.h>
#include "vector3.h"

typedef struct{
	int r, g, b, a;
} Color;

class Window{
public:
	int height;
	int width;

	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;


	Window();
	int createWindow(const char *title, int width, int height);
	int createRenderer();
	void renderClear();
	void drawPoint(int x, int y);
	void setColor(Color color);
	void present();
	void line(int x1, int y1, int x2, int y2, Color color);
	void drawLine(Point p1, Point p2, Color color);
	void drawTriangle(Triangle tri, Color color);
	void quit();
};

#endif