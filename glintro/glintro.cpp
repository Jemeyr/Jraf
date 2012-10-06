#include "SDL/SDL.h"

int main (int argc, char* args[])
{
	SDL_Surface* jraf 	=	NULL;
	SDL_Surface* screen 	=	NULL;
	SDL_Surface* loadImage 	=	NULL;

	SDL_Init(SDL_INIT_EVERYTHING);

	//Set up screen 
	screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE ); 
	SDL_WM_SetCaption( "GIRAFFE", NULL);

	//Load image 
	loadImage = SDL_LoadBMP( "jraf.bmp" );


	jraf = SDL_DisplayFormat(loadImage);
	
        Uint32 colorkey = SDL_MapRGB( jraf->format, 0xFF, 0, 0xFF );
	

        Uint32 bgcolor = SDL_MapRGB( screen->format, 0, 0, 0 );
	

	SDL_SetColorKey( jraf, SDL_SRCCOLORKEY, colorkey );

	SDL_Rect offset;

	offset.y = 0;
	offset.x = 640;


	for(int i = 640; i > -640; i--)
	{
		offset.x = i;
		SDL_FillRect(screen, NULL, bgcolor);
			
		 //Apply image to screen 
		SDL_BlitSurface( jraf, NULL, screen, &offset ); 

		//Update Screen 
		SDL_Flip( screen ); 

		//Pause 
		SDL_Delay(16);

	}

 	//Free the loaded image 
	SDL_FreeSurface( jraf ); 
	
	//Quit SDL 
	SDL_Quit(); 
	return 0; 
}

