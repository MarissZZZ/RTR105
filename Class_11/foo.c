#include "foo.h"    /* Always include the header file that declares something
                     * in the C file that defines it. This makes sure that the
                     * declaration and definition are always in-sync.  Put this
                     * header first in foo.c to ensure the header is self-contained.
                     */
#include <stdio.h>
#include <string.h>

/**
 * This is the function definition.
 * It is the actual body of the function which was declared elsewhere.
 */
void foo(int id, char *name)
{
   // fprintf(stderr, "foo(%d, \"%s\");\n", id, name);
    /* This will print how foo was called to stderr - standard error.
     * e.g., foo(42, "Hi!") will print `foo(42, "Hi!")`
     */
    printf("(izdruka no foo funkcijas) name atrašanās vieta atmiņā: %p\n",name);
    printf("(izdruka no foo funkcijas) name vērtība: %s\n",name);
    printf("(izdruka no foo funkcijas) name adreses atrašanās vieta: %p\n",&name);

    printf("(izdruka no foo funkcijas) id atrašanās vieta atmiņā: %p\n",&id);
    printf("(izdruka no foo funkcijas) id vērtība: %d\n",id);

    //name = "car"; // NB! tā tas ar simbolu masīvu nestrādā
    strcpy(name, "car");
    //strmcpy
    //memcpy
    id = 50;

}
