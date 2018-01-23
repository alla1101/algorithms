#include <stdio.h>

int main (int argc, char *argv[]){

	int i=0;

	//go through each string in argv
	//why am i skipping argv[0]


	char *gates[]={"gate1","gate2","gate3"};

	gates[0]=argv[0];

	argv[1]=gates[1];
	
	for(i=0;i<argc;i++){

		printf("argv[%d]=%s \n",i,argv[i]);

	}

	for (i = 0; i < 3; i++){

		printf("gate[%d]=%s\n",i,gates[i]);

	}

	printf("size of gates => %ld \n",sizeof(gates));

	// thought of my own way to print a string array without using its number directly
	//although i think using counter in structured type is much better

	long y=0;
	
	for(i=0;sizeof(gates)-y!=0;i++){

		printf("2nd_gate[%d]=%s\n",i,gates[i]);

		y+=sizeof(gates[i]);

	}

	return 0;

} 