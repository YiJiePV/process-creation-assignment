/**Karena Qian
 * Assignment #1 - Process creation
 * CSC 3350
 * April 14, 2023
 * **/

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc > 3 || argc < 2){
		fprintf(stderr, "Incorrect number of arguments for simpleSleep\n");
		return -1;
	}
	int sec = 0;
	for(long unsigned int i = 0; i < strlen(argv[argc-1]); i++){
		sec *= 10;
		sec += argv[argc-1][i] - '0';
	}	
	sleep(sec);
	printf("sleep program called with argument %d\n", sec);
	return 0;
}
