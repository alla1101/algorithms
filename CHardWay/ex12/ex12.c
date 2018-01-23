#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Forward Declaration
void print_letters(char arg[]);
void print_arguments(int argc, char *argv[]);

//Main Functions
int main(int argc, char *argv[]){

	print_arguments(argc,argv);

	return 0;

}

void print_arguments(int argc, char *argv[]){
	int i=0;

	for(i=0;i<argc;i++){
		
		print_letters(argv[i]);
	
	}
}

void print_letters(char arg[]){
	int i=0;

	for(i=0;i<strlen(arg);i++){

		if(isalpha(arg[i]) || isblank(arg[i])){

			printf(" '%c' == %d",arg[i],arg[i]);

		}
		printf("\n");
	}
}