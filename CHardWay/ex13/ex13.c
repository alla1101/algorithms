#include <stdio.h>

int main(int argc, char *argv[]){

	//create two arrays we care about
	
	int ages[]={10,20,30,40};

	char *names[]={"alla","ali","mustafa","ahmed"};

	//get the size of ages

	int count = sizeof(ages)/sizeof(int);

	int i=0;

	for(i=0;i<count;i++){

		printf("%s has been alive for %d years\n",names[i],ages[i]);
	}

	printf("--------------------------\n");

	//setting up pointers

	int *cur_age=ages;

	char **cur_name=names;

	//away to use pointers

	for(i=0;i<count;i++){

		printf("%s is %d years old\n",*(cur_name+i),*(cur_age+i));

	}

	printf("--------------------------\n");

	//a third way to use pointers

	for(i=0;i<count;i++){

		printf("%s is %d years old\n",cur_name[i],cur_age[i]);

	}

	printf("--------------------------\n");

	//a forth way to handle pointers in a complex and stupid way

	for(cur_name=names,cur_age=ages;(cur_age-ages)<count;cur_age++,cur_name++){

		printf("%s is %d years old\n",*cur_name,*cur_age);

	}

	printf("--------------------------\n");

	return 0;

}