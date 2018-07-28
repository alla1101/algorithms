/*	
		experiment 18
	
	Code to use functions as pointers 
*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
//alla
// creating a fake type for function pointer

typedef int (*compare_cb)(int a,int b);

int sorted_order(int a, int b);

int reverse_order(int a, int b);

int strange_order(int a, int b);

void test_sorting(int *numbers,int count, compare_cb cmp);

int *bubble_sort(int *numbers,int count, compare_cb cmp);

void die(const char *message);

int main(int argc, char *argv[]){
	
	if (argc < 2)
	{
		die("usage: ./ex16 1 9 7 3 4");
	}

	int count=argc-1;

	int i = 0 ;

	char **input=argv+1;

	int *numbers=malloc(sizeof(int)*count);

	if(!numbers){

		die("memory b3ed");

	}

	printf("the numbers you entered\n");

	for(i=0;i<count;i++){

		numbers[i]=atoi(input[i]);

		printf("[%d]=%d\n",i,*(numbers+i));
	
	}

	test_sorting(numbers,count,sorted_order);

	test_sorting(numbers,count,reverse_order);

	test_sorting(numbers,count,strange_order);

	free(numbers);

}

void test_sorting(int *numbers,int count, compare_cb cmp){

	int *sorted=bubble_sort(numbers,count,cmp);

	if(!sorted){

		die("failed to sort");

	}

	int i =0;

	printf("after being sorted\n");

	for(i=0;i<count;i++){

		printf("[%d]=%d\n",i,*(sorted+i));
	
	}

	free(sorted);

}

void die(const char *message){

	if(errno){

		perror(message);
	
	}else{

		printf("%s\n",message);

	}

	exit(1);
}

int sorted_order(int a, int b){

	return a - b;

}

int reverse_order(int a, int b){

	return b - a;

}

int strange_order(int a,int b){

	if(a==0 || b==0){

		return 0;

	}else{

		return a%b;
	
	}
}

int *bubble_sort(int *numbers,int count, compare_cb cmp){

	int tmp=0;
	int i=0;
	int j=0;
	
	int *target=malloc(sizeof(int)*count);
	
	memcpy(target,numbers,count*sizeof(int));
	
	if(!target){

		die("memcpy didn't work");
	
	}
	
	for(i=count-1;i>0;i--){
	
		for(j=0;j<i;j++){

			if(cmp(target[j],target[j+1]) > 0){
				
				tmp=target[j];
				target[j]=target[j+1];
				target[j+1]=tmp;

			}
		
		}
	}

	return target;
}