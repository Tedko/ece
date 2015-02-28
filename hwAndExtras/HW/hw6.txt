#include <stdio.h>

/* Define constants */

int main()
{
   /*********************/
   /* Declare variables */
   /*********************/
   int a,b,c;	/* counters for the input logic values */
   int result;

   /*************************************/
   /* Compute and print the truth table */
   /*************************************/
   printf("            YZ   \n");	/* print truth table header */
   printf(" X  | 00  01  11  10\n");
   printf(" --------------------\n");

   /* cycle through all input bit combinations */
   for ( a = 0; a <= 1; a = a + 1 )
   {  printf(" \n");
      printf("  %d |", a);
      for ( b = 0; b <= 1; b = b + 1 )
      {

        if (b==0)
        {
         for ( c = 0; c <= 1; c = c + 1 )
         {
            result =(!a )||(!b && c)||(a && b && (!c));		/* compute desired logical operation */

            printf("  %d ", result);
         }
        }
        else

        {
          for ( c = 1; c >= 0; c = c - 1 )
          {
             result =(!a )||(!b && c)||(a && b && (!c));		/* compute desired logical operation */

             printf("  %d ", result);
          }
        }

      }
   }

   return 0;
}


/**
OUTPUT:


            YZ
 X  | 00  01  11  10
 --------------------

  0 |  1   1   1   1
  1 |  0   1   0   1 






**/
