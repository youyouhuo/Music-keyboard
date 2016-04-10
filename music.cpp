
// for play sound

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

//for file read

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

// for keyboard event

#include<linux/input.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

//The music that will be played

Mix_Chunk *Music[90];

static int FileLength=0;


char name[90][8];




void readByLine()  
{  
    fstream outFile;  
    outFile.open("name.txt",ios::in);  
    cout<<"inFile.txt"<<"--- all file is as follows:---"<<endl;  
    while(!outFile.eof())  
    {  
        outFile.getline(name[FileLength++],8,'\n');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束  
 
    }  
    outFile.close();  
}  


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}else{
	
	 //Initialize SDL_mixer
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}

	}

	return success;
}


bool loadMusic(){

//Loading success flag
    bool success = true;

   Mix_Chunk *temp = NULL;

   for(int i=0;i<FileLength;++i){

	temp=Mix_LoadWAV(name[i]);

        if(temp==NULL){
	 printf( "Failed to load  music! SDL_mixer Error: %s\n", Mix_GetError() );
         success = false;
	}

	Music[i]=temp;

   }
    return success;

}




void close()
{
   

    //Free the sound effects

    for(int i=0;i<FileLength;++i){

	Mix_FreeChunk(Music[i]);
	Music[i]=NULL;

    }


    //Quit SDL subsystems
    Mix_Quit();
    SDL_Quit();
}

int main( int argc, char* args[] )
{

	int keys_fd;
	char ret2[2];
	struct input_event t;
	


	//ReadDataFromFileLBLIntoString();

	readByLine();
	FileLength=88;

     

	keys_fd=open("/dev/input/event3",O_RDONLY);

	if(keys_fd<=0)
	{
		printf("open /dev/input/event3 device error!\n");
		return 0;
	}

	

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
		return 0;
	}
	
	//Load music
	if( !loadMusic() )
	{
		printf( "Failed to load music!\n" );
		return 0;
	}
			
	//Main loop flag
	bool quit = false;

	//While application is running
	while( !quit )
	{
			
	if( read(keys_fd,&t,sizeof(struct input_event)) ==sizeof(struct input_event) )
	  {
	
		if(t.type==EV_KEY)
		{
			if(t.value==1)
			{
			
			 Mix_PlayChannel( -1, Music[t.code], 0 );					

			if(t.code==KEY_ESC)
			break;
		
		
			}
	
		}
	
	  }


	}

	close(keys_fd);

	close();

	return 0;
}






