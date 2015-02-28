/*
 *	dungeon.c
 *	Douglas L. Jones
 *	University of Illinois at Urbana-Champaign
 *	September 29, 2012
 *
 *	(c) 2012 by Douglas L. Jones
 *	This work is made available according to the
 *             Creative Commons "Attribution" license
 *	http://creativecommons.org/licenses/by/3.0/
 *
 *      edited by S.S. Lumetta, 11 October 2012
 *
 *  dungeon.c: a simple maze game
 */
#include <stdio.h>

/* Define constants */

int
main ()
{
   /*********************/
   /* Declare variables */
   /*********************/
   int flag_play;	/* indicates whether to play the game again */
   int room;	/* indicates current room */
   int choice;

   flag_play = 1;
   while ( flag_play == 1 )
   {
   /***************/
   /* Play a game */
   /***************/
      room = 0;
      while ( room < 3 )	/* Explore the maze */
      {
         if ( room == 0 )
         {
            printf("You wake in a dungeon, chained to the wall!\n");
            printf("The chains are rusty, and you manage to break free.\n");
            printf("You search the room carefully, ");
            printf("and you discover two hidden exits;\n");
            printf("a tunnel under a large flagstone, ");
            printf("and an air vent large enough to crawl through.\n");
            printf("Which exit do you wish to explore?\n");
            printf("Enter 0 for flagstone, or 1 for air vent.  ");
            scanf("%d", &choice);
            if ( choice == 0 ) { room = 3; }
            if ( choice == 1 ) { room = 1; }
         }
         else if ( room == 1 )
         {
            printf("You emerge in what appears to be a large cavern.\n");
            printf("A bat brushes your head as it flies past.\n");
            printf("Groping around in the darkness, you discover a ");
	    printf("crawlway and a fissure you think you can fit through.  ");
	    printf("There also seems to be an opening behind a large ");
	    printf("stalagmite.\n");
            printf("Which exit do you wish to explore?\n");
            printf("Enter 0 for crawlway, 1 for fissure, or 2 for behind ");
	    printf("stalagmite.  ");
            scanf("%d", &choice);
            if ( choice == 0 ) { room = 2; }
            if ( choice == 1 ) { room = 3; }
            if ( choice == 2 ) { room = 1; }
         }
         else if ( room == 2 )
         {
            printf("The passage expands into a small cave with an ");
	    printf("underground waterfall.\n");
            printf("The passage continues on, but you feel another passage ");
	    printf("behind the waterfall.\n");
            printf("Enter 0 for behind waterfall, or 1 for continue,or 2 for sleeping ");
	    printf("along passage.  ");
            scanf("%d", &choice);
            if ( choice == 0 ) { room = 1; }
            if ( choice == 1 ) { room = 4; }
            if ( choice == 2 ) { room = 5; }
         }
         printf("\n");

         printf("\n");
      }

      if ( room == 5 )
      {
         printf("The passage expands into a small cave with an ");
   printf("underground waterfall.\n");
         printf("The passage continues on, but you feel another passage ");
   printf("behind the waterfall.\n");
         printf("Enter 0 for behind waterfall, 1 for continue \n");
         scanf("%d", &choice);
         if ( choice == 0 ) { room = 3; }
         if ( choice == 1 ) { room = 4; }
      
      }
      /* End of game conditions */
      if ( room == 3 )
      {
         printf("You feel the passage widening and a draft of fresh air.\n");
         printf("On your next step, you fall into a deep pit and die.\n");
      }
      if ( room == 4 )
      {
         printf("You see a light in the distance and climb toward it.\n");
         printf("You emerge on the surface in a beautiful forest.\n");
         printf("You have successfully escaped; you are free!\n");
      }
      printf("\n");
      printf("\nWould you like to play again?  Enter 1 for yes, 0 for no.  ");
      scanf("%d", &flag_play);
      printf("\n");
   }

   return 0;
}
