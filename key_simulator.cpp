#include<stdio.h>
#include<linux/input.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
using namespace std;
int main(void){

int keys_fd;
char ret2[2];
struct input_event t;
keys_fd=open("/dev/input/event3",O_RDONLY);

if(keys_fd<=0)
	{
		printf("open /dev/input/event3 device error!\n");
		return 0;
	}

	while(1){
		if( read(keys_fd,&t,sizeof(struct input_event)) ==sizeof(struct input_event) )
			{
	
			if(t.type==EV_KEY)
				{
					if(t.value==0||t.value==1)
					{
						printf("key %d %s \n ",t.code,(t.value)?"Pressed ":"Reseased");
			
						if(t.code==KEY_ESC)
							break;
		
		
					}
	
				}
	
			}



		}

close(keys_fd);

return 0;
}
