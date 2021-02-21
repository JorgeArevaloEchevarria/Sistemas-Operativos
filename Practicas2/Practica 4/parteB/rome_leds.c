#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

const char device[]="/dev/leds";



void delay(){
	int i,j;
	for(i = 0; i < 99999 ; i++)
		for(j=0; j< 2211 ; j++);
}

int main(){
	FILE* device_file;
	int i,j;
	char buf[]={"123"};

	for(j=0; j<5; j++){
		for(i = 0 ; i< 3; i++){
			device_file = fopen(device, "w");
			fwrite(&buf[i], sizeof(char), 1, device_file);
			fclose(device_file);
			system("sleep 1");
		}
	}

	device_file = fopen(device, "w");
	fprintf(device_file, "123");
	fclose(device_file);

	return 0;
}
