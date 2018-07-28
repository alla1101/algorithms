#include <stdio.h>

int main(int argc, char *argv[]){

	int numbers[4]={0};

	char names[4]={'a'};

	//first print them out raw

	printf("numbers: %d %d %d %d\n",numbers[0],numbers[1],numbers[2],numbers[3]);

	printf("names: %c %c %c %c \n",names[0],names[1],names[2],names[3]);

	printf("names string format: %s \n",names);

	//setup the numbers

	numbers[0]=0;

	numbers[1]=1;

	numbers[2]=2;

	numbers[3]=3;

	//setup the names

	names[0]='a';

	names[1]='b';

	names[2]='c';

	names[3]='\0';

	//printout the inisialized variables

	printf("init numbers: %d %d %d %d\n",numbers[0],numbers[1],numbers[2],numbers[3]);

	printf("init names: %c %c %c %c \n",names[0],names[1],names[2],names[3]);

	printf("init names string format: %s \n",names);

	//another way to use names

	char *words="alla";

	printf("words: %s\n",words);

	printf("words each : %c %c %c %c %c",words[0],words[1],words[2],words[3],words[4]);

	return 0;
}