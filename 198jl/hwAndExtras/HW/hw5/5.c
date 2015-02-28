#include <stdio.h>

/* Define constants */

int main()
{
   /*********************/
   /* Declare variables */
   /*********************/
   unsigned int a,b,c,d;	/* counters for the input logic values */
   unsigned int p1,p2,p3;

   /*************************************/
   /* Compute and print the truth table */
   /*************************************/
   printf("  A  B  C  D  | OUT \n");	/* print truth table header */
   printf("--------------|---------------------\n");

   /* cycle through all input bit combinations */
   for ( a = 0; a <= 1; a = a + 1 )
   {
      for ( b = 0; b <= 1; b = b + 1 )
      {
         for ( c = 0; c <= 1; c = c + 1 )
         {
           for ( d = 0; d <= 1; d = d + 1 )
            {
              p1=((!a)&(!b)&d)|((!a)&b&!d)|(a&b&d)|(a&(!b)&(!d));
              p2=((!a)&(!c)&d)|((!a)&c&!d)|(a&c&d)|(a&(!c)&(!d));
              p3=((!b)&(!c)&d)|((!b)&c&!d)|(b&c&d)|(b&(!c)&(!d));

              printf("  %u  %u  %u  %u  |  %u %u %u %u %u %u %u \n", a, b, c, d, d,c,b,p3,a,p2,p1);
            }
         }
      }
   }

   return 0;
}


/******************
  A  B  C  D  | OUT
--------------|---------------------
  0  0  0  0  |  0 0 0 0 0 0 0
  0  0  0  1  |  1 0 0 1 0 1 1
  0  0  1  0  |  0 1 0 1 0 1 0
  0  0  1  1  |  1 1 0 0 0 0 1
  0  1  0  0  |  0 0 1 1 0 0 1
  0  1  0  1  |  1 0 1 0 0 1 0
  0  1  1  0  |  0 1 1 0 0 1 1
  0  1  1  1  |  1 1 1 1 0 0 0
  1  0  0  0  |  0 0 0 0 1 1 1
  1  0  0  1  |  1 0 0 1 1 0 0
  1  0  1  0  |  0 1 0 1 1 0 1
  1  0  1  1  |  1 1 0 0 1 1 0
  1  1  0  0  |  0 0 1 1 1 1 0
  1  1  0  1  |  1 0 1 0 1 0 1
  1  1  1  0  |  0 1 1 0 1 0 0
  1  1  1  1  |  1 1 1 1 1 1 1



*******************/
