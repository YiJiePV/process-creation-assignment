/**Karena Qian
 * Assignment #1 - Process creation
 * CSC 3350
 * April 14, 2023
 * **/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

double forkExecWait(int count, char* arguments[]){
	//launch sleepy program with fork(), exec(), and wait()
	time_t start = time(NULL);
	int currProcess = fork();
	//fork failed (exit)
	if(currProcess < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	//at child process
	else if(currProcess == 0){
		int success = execvp(arguments[1], arguments);
		if(success == -1){
			printf("exec failed\n");
			return -1.0;
		}
	}
	//at parent process
	else{
		int waitForChild = wait(NULL);
	}
	time_t end = time(NULL);
	return difftime(end, start) * 1000;
}

void addSpaces(char* output){
	int len = strlen(output);
	memset(output+len, ' ', 1);
	output[len + 1] = '\0';
}

double usingSystem(int count, char* arguments[]){
	//launch sleepy program with only system()
	//set up command param
	char commandBuf[1000];
	strcpy(commandBuf, arguments[1]);
	for(int i = 2; i < count; i++){
		addSpaces(commandBuf);
		strncat(commandBuf, arguments[i], 100);
	}
	time_t start = time(NULL);
	int status = system(commandBuf);
	time_t end = time(NULL);
	if(status == -1){
		printf("system failed\n");
		return -1.0;
	}
	return difftime(end, start) * 1000;
}

int main(int argc, char* argv[]){
	if(argc < 2){
		fprintf(stderr, "Missing argument(s) for second process\n");
		return 1;
	}
	
	//for storing recorded times
	double firstSum = 0;
	double secondSum = 0;
	
	printf("Executing %s with fork, exec, and wait....\n", argv[1]);
	//launch sleepy program with fork(), exec(), and wait()
	for(int i = 0; i < 7; i++){
		firstSum += forkExecWait(argc, argv);
	}
	printf("Finished executing\n");
	//double firstTime = forkExecWait(argc, argv);
	
	printf("Executing %s with only system.....\n", argv[1]);
	//launch sleepy program with only system()
	for(int i = 0; i < 7; i++){
		secondSum += usingSystem(argc, argv);
	}
	printf("Finished executing\n");
	//double secondTime = usingSystem(argc, argv);

	printf("Time of fork(), exec(), and wait(): %.2f\n", firstSum / 7);
	printf("Time of system(): %.2f\n", secondSum / 7);

	return 0;
}
