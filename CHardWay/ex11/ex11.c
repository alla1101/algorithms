#include <stdio.h>

int main(int argc,char *argv[]){

	if(argc!=2){

		puts("enter one Argument you stupid potato");

		return 1;
	}

	int i=0;

	char letter;

	for(i=0; argv[1][i]!='\0'; i++){

		letter=argv[1][i];

		switch(letter){

			case 'a':
			case 'A':

				puts("found an a-A");
			
				break;
			
			default:

				puts("didn't find an a-A");
				
		}

	}

	return 0;

}