#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

void render()
{

	glClear( GL_COLOR_BUFFER_BIT );

	glBegin( GL_QUADS);
		glVertex2f(-15.f, -15.f);
		glVertex2f(-15.f, 15.f);
		glVertex2f(15.f, -15.f);
		glVertex2f(15.f, 15.f);
	glEnd();

	SDL_GL_SwapBuffers();
}


int main (int argc, char* args[])
{

	SDL_Surface* screen = SDL_SetVideoMode( 640, 480, 16, SDL_OPENGL | SDL_FULLSCREEN );

	if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	 
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 ); // *new*
	 
	SDL_WM_SetCaption( "GIRAFFE", NULL);

	glEnable( GL_TEXTURE_2D );
 
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	 
	glViewport( 0, 0, 640, 480 );
	 
	glClear( GL_COLOR_BUFFER_BIT );
	 
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	 
	glOrtho(0.0f, 640, 480, 0.0f, -1.0f, 1.0f);
	 
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

/*
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

	int y = 0;

	int state = 1;

	for(int i = 640; i > -640; i-=5)
	{
		
		y += 3*state;
		if(y > 5)
		{
			state = -1;
		}
		if(y < -5)
		{
			state = 1;
		}	

		offset.y = y;
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
*/
	int h = 0;
	while(h++ < 50000000){
		render();
	}
	
	//Quit SDL 
	SDL_Quit(); 
	return 0; 
}



