/* fopen example */
#include <stdio.h>

int main ()
{
  FILE * pFile;
  char c;

  pFile = fopen ("myfile.txt","w");
  if (pFile!=NULL)
  {
    printf("Norāde uz failu - %p\n", pFile);
    //printf("Norāde uz nosuakumu - %\n", pFile); faila nosaukumu nevar izgūt

    fputs ("fopen - teksta ieraksts failā\n",pFile);
    scanf("%c", &c);
    fclose (pFile);
  }
  else
  {
    fputs("fopen - failu nav izdevies atvērt\n", stderr);
  }
  return 0;
}
