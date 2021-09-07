#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

//points
typedef struct {
    double x, y;
} Vector2;

typedef struct {
    double x, y, z;
} Vector3;

//color
typedef struct {
    int r, g, b, a;
} Color;


//global variables
const int width = 800;
const int height = 600;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

const Color white = {0xff, 0xff, 0xff, 0xff};
const Color red = {0xff, 0x00, 0x00, 0xff};
const Color green = {0x00, 0xff, 0x00, 0xff};
const Color blue = {0x00, 0x00, 0xff, 0xff};




//bresenham's line drawing algorithm
void line(Vector2 *point1, Vector2 *point2, Color color, float steps) {
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (float t = 0.; t < 1.; t += steps) { 
        float x = point1->x + (point2->x-point1->x)*t; 
        float y = point1->y + (point2->y-point1->y)*t;
        SDL_RenderDrawPoint(renderer, x, y);
    } 
}


void triangle(Vector2 *point1, Vector2 *point2, Vector2 *point3, Color color, float steps){
    line(point1, point2, color, steps); //line between point1 and point 2
    line(point2, point3, color, steps); //line between point2 and point 3
    line(point3, point1, color, steps); //line between point3 and point 1
}


void beizer(Vector2 *point1, Vector2 *point2, Vector2 *point3, Vector2 *point4, Color color, float steps){
    //4 point beizer curve
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for(float t = 0; t < 1; t += steps){
        float x = (1-t)*(1-t)*(1-t)*point1->x + 3*(1-t)*(1-t)*t*point2->x + 3*(1-t)*t*t*point3->x + t*t*t*point4->x;
        float y = (1-t)*(1-t)*(1-t)*point1->y + 3*(1-t)*(1-t)*t*point2->y + 3*(1-t)*t*t*point3->y + t*t*t*point4->y;
        SDL_RenderDrawPoint(renderer, x, y);
    }
}


int main(int argc, char *argv[]){

    //SDL stuff
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL Init failed.\n");
        return 1;
    }

    window = SDL_CreateWindow("Sphagetti renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    if(window == NULL){
        printf("Cannot init the window.\n");
        SDL_Quit();
        return 2;
    }

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

    bool quit = false;
    SDL_Event event;

    while (!quit){
        while (SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
                quit = true;
            }
        }

        SDL_RenderClear(renderer); //clear the renderer


        //do some processing here, for now we'll draw the triangle
        Vector2 point1 = {50, 80};
        Vector2 point2 = {400, 300};
        Vector2 point3 = {80, 400};
        float steps = 0.002;

        triangle(&point1, &point2, &point3, green, steps);


        Vector2 point4 = {60, 80};
        Vector2 point5 = {400, 40};
        Vector2 point6 = {80, 420};
        Vector2 point7 = {275, 63};
        beizer(&point4, &point5, &point6, &point7, green, steps);

        //set back the old color, so that we can see the point
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);

        //present what we drew
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}