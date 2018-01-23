#include <stdio.h>

int main(int argc, char *argv[]){

	int i=0;

	if(argc == 1){

		puts("you have one input");

	}else if(argc >1 && argc <=4 ){

		puts("here are your arguments");

		for(i=0; i < argc ; i++){

			printf("argv[%d]=%s\n",i,argv[i]);

		}

	}else{

		printf("go home, you're drunk");

	}
}