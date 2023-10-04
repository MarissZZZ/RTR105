/* scanf example */
#include <stdio.h>

int main ()
{
  char str [80];
  int TagGads;
  int DzimGads;
  int gadi;

  printf ("Kāds ir tavs vārds: ");
  scanf ("%79s",str); 

  printf("Kurš gads ir tagad?\n");
  scanf("%d", &TagGads);
  printf("Kurā gadā Tu esi dzimis?\n");
  scanf("%d", &DzimGads);

  gadi = TagGads - DzimGads;

  printf ("%s , %d gadus vecs.\n", str, gadi);

  return 0;

}
