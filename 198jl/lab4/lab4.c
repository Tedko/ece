#include<stdio.h>
#include<math.h>

int main()
{
    int a = 256;

    /*for (a = 256; a > 1; a = sqrt(a))
    {
        printf("%d\n", a);
    }

    */

    while (a > 2)
    {
        printf("%d\n", a);
        a = sqrt(a);
    }

    printf("%d\n", 1);

}
