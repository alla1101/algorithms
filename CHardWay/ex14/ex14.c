#include <stdio.h>
//standard input and output
#include <assert.h>
//abort program if result of assert(condition) is false
#include <stdlib.h>
//used for malloc and free
#include <string.h>
//handle strings
struct person{
	
	char *name;
	
	int age;
	
	int height;
	
	int weight;

};

struct person *Person_Create(char *name,int age, int height, int weight){

	struct person *who=malloc(sizeof(struct person));

	assert(who != NULL);

	who->name=strdup(name);

	/*
	function returns a pointer to a  new  string  which  is  a duplicate  
	of the string s.  Memory for the new string is obtained with malloc,
	and can be freed with free.
	*/

	who->age=age;

	who->height=height;

	who->weight=weight;

	return who;

}

void Person_Destroy(struct person *who){

	assert(who != NULL);

	free(who->name);

	free(who);

}

void Person_Print(struct person *who){

	printf("who's name is %s \n",who->name);
	printf("who's age is %d \n",who->age);
	printf("who's height is %d \n",who->height);
	printf("who's weight is %d \n",who->weight);

}

int main(int argc, char *argv[]){

	//make two people structures

	struct person *joe=Person_Create("joe alex",15,10,110);

	struct person *alex=Person_Create("alex joe",16,11,120);

	//print their location and their info

	printf("joe is at the location %p \n",joe);

	Person_Print(joe);

	printf("alex is at the location %p \n",alex);

	Person_Print(alex);

	//destroy the pointers

	Person_Destroy(joe);

	Person_Destroy(alex);

	return 0;

}