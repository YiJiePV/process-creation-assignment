/**Karena Qian
 * Assignment #1 - Process creation
 * CSC 3350
 * April 14, 2023
 * **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void loops(int l, int factor){
	int n = l*45;
	while(n > -n){
		int m = n-1;
		while(m > (-m / factor)){
			int o = m-1;
			while(o > 0){
				int p = o-1;
				while(p > (p / factor)){
					p--;
				}
				o--;
			}
			m--;
		}
		n--;
	}
}

int main(int argc, char* argv[]){
	if(argc > 4 || argc < 3){
		fprintf(stderr, "Incorrect number of arguments to 'fake' factorial\n");
		return 1;
	}
	srand(time(0));
	int l = 0;
	for(long unsigned int i = 0; i < strlen(argv[argc-2]); i++){
		l *= 10;
		l += argv[argc-2][i] - '0';
	}
	int factor = 0;
	for(long unsigned int i = 0; i < strlen(argv[argc-1]); i++){
		factor *= 10;
		factor += argv[argc-1][i] - '0';
	}
	loops((l % (20 - 8 + 1)) + 8, (factor % (8 - 4 + 1)) + 4);
	printf("loops done\n");
	return 0;
}
