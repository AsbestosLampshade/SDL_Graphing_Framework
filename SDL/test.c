//#include<graphics.h>
#include<stdbool.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#define width 640
#define height 480
int main(int argc,char *argv[]){
	SDL_Window* window=NULL;
	SDL_Renderer* renderer;
	
	SDL_Surface* screenSurface = NULL;

	int i;

	if(SDL_Init(SDL_INIT_VIDEO)<0){
		printf("SDL Could not initialize: %s\n",SDL_GetError());
	}
	else{
		window=SDL_CreateWindow("SDL Tutorial",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
		renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
		SDL_SetRenderDrawColor(renderer,0,0,255,255);
		for(i=0;i<width;i++){
			SDL_RenderDrawPoint(renderer,i,240);
			SDL_RenderPresent(renderer);
		}
		SDL_Event e;bool quit = false;while(quit==false){while(SDL_PollEvent(&e)){if(e.type ==SDL_QUIT)quit=true;}}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
