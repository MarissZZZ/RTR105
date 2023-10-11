#include <stdio.h>
#define N 10
#define X 7

int main(void)
 {
 //int N; // NB! nedrīkst!
 //N = 10 // NB! nedrīkst mainīt!
 int i = 0;
 printf("i mainīgā sākuma vērtība: %d\n", i);

 i = i + 1; 
 while(i<=N) // NB! 10 <= 10 rezultāts ir 1(dec) - nav 0 => cikls vēl nostrādās (pie 11 apstāsies)
 {
 printf("(%d.) i mainīgā nākamā vērtība - %d (tā ir mazāka par %d)\n",i,i,N);
 // i = i + 1; // NB! obligāti jāmaina i vertība, citādāk būs bezgalīgs cikls
 if(i==X)
  {
  printf("X vērtība ir \"trāpījusies\", aprēķinu izbeidzam!\n");
  break;
  //continue; // continue esot šeit - pirms i = i + 1;
  //return 0;
  }
 i = i + 1; // NB! obligāti jāmaina i vertība, citādāk būs bezgalīgs cikls
 //i++;
 //i += 1;
 }
 
 printf("(%d.) i mainīgā nākamā vērtība ir kļuvusi lielāka par %d\n",i,N);
 printf("Saskaitīšanu apturam!\n");

 return 0;
 }
