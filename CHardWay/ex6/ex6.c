#include <stdio.h>

int main(int argc, char *argv[]){

	int areas[]={1,2,10,13,1,23};

	char name[]="alla";

	char fullname[]={'a','l','l','a',' ','b','a','r','a','k','a','t','\0'};

	//warning: in some systems you may have to change %ld in this code to %u since it will use ints

	printf("the size of an int:%ld\n",sizeof(int));

	printf("the size of areas (int[]): %ld\n",sizeof(areas));

	printf("the number of ints in areas %ld\n",sizeof(areas)/sizeof(int));

	printf("areas[0]=%d, areas[1]=%d\n",areas[0],areas[1]);

	printf("the size of char is: %ld \n",sizeof(char));

	printf("the size of name (char[]): %ld \n",sizeof(name));

	printf("the number of chars in name is : %ld\n",sizeof(name)/sizeof(char));

	printf("the size of full name (char[]) is : %ld\n",sizeof(fullname));

	printf("the number of chars in full name is: %ld\n",sizeof(fullname)/sizeof(char));

	printf("my name is %s, and my full name is %s \n",name,fullname);

	return 0;
}