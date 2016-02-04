// From class, Wed Feb 3 2016
// oddities surrounding macro expansion

#include <stdio.h>
#include <math.h>


/* this one causes problems... */
/* #define PLUS_TEN(x) x+10 */

#define PLUS_TEN(x) ((x)+10)

/* this evaluates the substitution of x two times */
#define SQUARE(x) ((x)*(x))

// this captures free variables called temp!
#define SWAP(v1, v2) { int temp=v1; v1=v2; v2=temp; }

int main(int argc, char *argv[])
{

    // parentheses in the macro are important
    printf("%d\n", PLUS_TEN(3));
    printf("%d\n", PLUS_TEN(3+1));
    printf("%d\n", PLUS_TEN(3+1)*10);


    printf("%d\n", SQUARE(10));
    printf("%lf\n", SQUARE(sqrt(10)));


    /* this works fine ... */

    /* int a = 5; */
    /* int b = 6; */

    /* printf("%d - %d\n", a, b); */
    /* SWAP(a,b); */
    /* printf("%d - %d\n", a, b); */

    

    /* this one does not, because temp is /captured/ */
    int a = 5;
    int temp = 6;

    printf("%d - %d\n", a, temp);
    SWAP(a,temp);
    printf("%d - %d\n", a, temp);

    return 0;
}
