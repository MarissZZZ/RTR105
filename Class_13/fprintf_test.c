/* fprintf example */
#include <stdio.h>
#include <string.h>

int main ()
{
   FILE * pFile;
   int n;
   char name [100];

   pFile = fopen ("myfile.txt","w");
   for (n=0 ; n<3 ; n++)
   {
     puts ("please, enter a name: ");
     //gets (name);

     fgets (name,sizeof(name), stdin); //One\n0
     for (int i=0; i<strlen(name)+1; i++)
       printf("%d ", name[i]);
     printf("\n");
     
     name[strcspn(name, "\n")] = 0; //One00
     
     fprintf (pFile, "Name %d [%-10.10s]\n",n+1,name);
   }
   fclose (pFile);

   return 0;
}
