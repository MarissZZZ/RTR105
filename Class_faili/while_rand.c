// https://cplusplus.com/reference/cstdlib/rand/
// https://cplusplus.com/reference/cstdlib/srand/
// https://cplusplus.com/reference/ctime/time/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{ 
	char i = 1;
	int flag = 1; 
	long long int counter_sum, counter =  0;;
	int gadijuma_skaitlu_generatora_grauds;


	gadijuma_skaitlu_generatora_grauds = time(NULL); // laiks sekundēs kopš 01.01.1970 00:00
	srand(gadijuma_skaitlu_generatora_grauds);
	printf("Laiks sekundēs kopš 01.01.1970 00:00 - %d\n",gadijuma_skaitlu_generatora_grauds);

	for(int i=0; i<10; i++)
	{
		counter = 1;
		flag = rand();
		while(flag)
		{
		counter ++;;
		flag = rand();
		}
		printf("counter = %lld (pēc cikla)\n", counter);
		counter_sum = counter_sum + counter;
		printf("Counter_sum: %lld\n", counter_sum); 
	}
	return 0;
}
