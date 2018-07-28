#include <stdio.h>

int main(int argc, char *argv[]){

	int bugs=100;

	double bugs_rate=1.2;

	printf("you have %d bugs at the imaginary rate of %f .\n",bugs,bugs_rate);

	long universe_of_defects= 1L * 1024L * 1024L * 1024L;

	printf("the universe has %ld bugs\n",universe_of_defects);

	double expected_bugs= bugs*bugs_rate;

	printf("you're expected to have %f bugs\n",expected_bugs);

	double part_of_universe = expected_bugs/universe_of_defects;

	printf("this is only a %e portions of the universe\n",part_of_universe);

	// this is a test that makes no sense, but b333 to hell with it, i will try it

	char nul_byte='\0';

	int care_persentage=bugs* nul_byte;

	printf("which means you should care %d%%\n",care_persentage);

	return 1;
}