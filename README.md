# Music-keyboard

this is project is about listening to keyboard event and play Piano key sound

# 0.about the project 
# 1.about SDL2 libs
# 2.about key board event
# 3.about play sound with SDL2 


# 0.about the project 

name.txt:           save sound file nam

key_simulator.cpp : the usage of keyboard events

music.cpp :         listening to keyboard and play piano key sound


Makefile :          compile the project

run.sh :            run Makefile and start the software


# when you run this project :

   first,you should get you keyboard event file ,either  event2 or event3 ,relpace it in file music.cpp,about event is shows in 2.about keyboard events.
   
  
   second ,you should install the SDL2 ,which shows in 1.about SDL2

# 1.about SDL2

before you run the project ,you should to install SDL libs first:

apt-get install libsdl2-dev   :for SDL2 libs

apt-get install libsdl2-mixer-dev :for SDL2 mixer libs  [to play sound]

for more detail you can go to :http://lazyfoo.net/tutorials/SDL/21_sound_effects_and_music/index.php 


# 2.about keyboard events

In linux , keyboard events can be retrieved by reading the file。

# use command ：  cat /proc/bus/input/devices
 
and it shows like this:


I: Bus=0019 Vendor=0000 Product=0001 Version=0000

N: Name="Power Button"

P: Phys=PNP0C0C/button/input0

S: Sysfs=/devices/LNXSYSTM:00/LNXSYBUS:00/PNP0A08:00/device:01/PNP0C0C:00/input/input0

U: Uniq=
H: Handlers=kbd event0 
B: PROP=0
B: EV=3
B: KEY=10000000000000 

I: Bus=0019 Vendor=0000 Product=0005 Version=0000
N: Name="Lid Switch"
P: Phys=PNP0C0D/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSYBUS:00/PNP0C0D:00/input/input1
U: Uniq=
H: Handlers=event1 
B: PROP=0
B: EV=21
B: SW=1

 I: Bus=0019 Vendor=0000 Product=0001 Version=0000
 N: Name="Power Button"
 P: Phys=LNXPWRBN/button/input0
 S: Sysfs=/devices/LNXSYSTM:00/LNXPWRBN:00/input/input2
 U: Uniq=
 H: Handlers=kbd event2 
 B: PROP=0
 B: EV=3
 B: KEY=10000000000000 0

#what we need it is like this

I: Bus=0011 Vendor=0001 Product=0001 Version=ab41

N: Name="AT Translated Set 2 keyboard"

P: Phys=isa0060/serio0/

S: Sysfs=/devices/platform/i8042/serio0/input/input3

U: Uniq=

H: Handlers=sysrq kbd event3 

B: PROP=0

B: EV=120013

B: KEY=402000000 3803078f800d001 feffffdfffefffff fffffffffffffffe

B: MSC=10

B: LED=7

# it shows that our keyboard event is event3,so we can read file : /dev/input/event3  to get every keyboard event




#the event struct is like this:

struct input_event { 

struct timeval time;  //the time of press key

__u16 type; //event type 

__u16 code; //which key 

__s32 value;//

};


#about the type :

EV_KEY:Key events , such as a keyboard key ( which key was pressed ) , left the right mouse button ( under non- strike ) and the like ;

EV_REL: Relative coordinates , mainly refers to moving the mouse event ( relative displacement ) ;

EV_ABS: Absolute coordinates , mainly refers to mobile touch screen events


#about the code : like this 
 #define KEY_RESERVED  0 
 #define KEY_ESC  1  
 #define KEY_1  2  
 #define KEY_2  3  
 #define KEY_3  4  
 #define KEY_4  5  
 #define KEY_5  6  
 #define KEY_6  7  
 #define KEY_7  8  
 #define KEY_8  9  
 #define KEY_9  10  
 #define KEY_0  11  
 #define KEY_MINUS  12  
 #define KEY_EQUAL  13  
 #define KEY_BACKSPACE  14  
 #define KEY_TAB  15  
 #define KEY_Q  16  
 #define KEY_W  17 
 #define KEY_E  18  
 #define KEY_R  19  
 #define KEY_T  20 
 
 #about value:
 
 If the event type code is EV_KEY, when the button is pressed a value of 1 , when you release the value is 0 ; 
 
 if the event type code is EV_REL, value is the positive values and negative values which represent the values of two different directions.


#for listening keyboard event ,this code is shows in file:key_simulator.cpp

#3.about play sound 

#init
if( SDL_Init(  SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	
	}else{
	
	 //Initialize SDL_mixer
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
				
				}

	}
#load music
        
        Mix_Chunk temp=Mix_LoadWAV(name[i]);

        if(temp==NULL){
	         printf( "Failed to load  music! SDL_mixer Error: %s\n", Mix_GetError() );
         
       	}


#play music 

    Mix_PlayChannel( -1, temp, 0 );	
    
 #close 
     
   Mix_FreeChunk(temp);
	  temp=NULL;

    //Quit SDL subsystems
    
    Mix_Quit();
    SDL_Quit(); 

for more example ,you can go to :http://lazyfoo.net/tutorials/SDL/21_sound_effects_and_music/index.php
