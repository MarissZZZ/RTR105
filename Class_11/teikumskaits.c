#include <string.h>
#include <stdio.h>

int main()
{
    char teikums[100];
    printf("Ievadiet teikumu: ");
    fgets(teikums, sizeof(teikums), stdin);

    int varduskaits = 0;

    printf("Vārdi ar 5 vai mazāk simboliem: ");
    char *vards = strtok(teikums, " \n");
    while (vards != NULL)
    {
    varduskaits++;
       if (strlen(vards) <= 5)
       {
       printf("%s ", vards);
       }
       vards = strtok(NULL, " \n");
    }
    printf("\nVisi vārdi no ierakstītā teikuma: %d\n", varduskaits);
    return 0;
}
