    /***********************************************************************
     * Name(s) Ella Berman and Jason Kunkel and Giovanna Romero                      *
     * Assignment name: Project 4                                           *
     *                                                                      *
     * Assignment for 4/28/2023                                             *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *    - referenced the namelist.c lab                                  *
     *   Help obtained                                                     *
     *     Clarification from Barbara and advice from Mae and Ray.                                                                                         *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Ella Berman and Jason Kunkel and Giovanna Romero                 *
     ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "project-4.h"

int main(void)
{
  int ticketCount = 0;//Keeps track of number of newTickets created
  int scanfVal = 0; //check to see if scanf worked correctly
  
  ticket_t * first_new = NULL; //pointer to the first new ticket
  ticket_t * first_assigned = NULL; //pointer to the first assigned ticket
  ticket_t * first_completed = NULL; //pointer to the first completed ticket
  
  char option[MAXSTRLEN+1];

  printf("\nThis program should be used by an employee at the help desk.\n");
  printf("Choose from the menu options below to manage tickets.\n\n");

  //User input
  while(1){
    printMenu();
    printf("Enter desired option: \n");
    scanfVal = scanf("%s", option);

    //check if scanf worked correctly
    if (scanfVal != 1)
    {
      printf("Error: enter one number, with no spaces.\n");
    }
    else{
      switch (option[0])
	{
	case '1':
	  ticketCount++;//number of new tickets created increases by 1
	  createNew (&first_new, ticketCount);
	  break;
	case '2': assignTicket(&first_new, &first_assigned);
	  break;
	case '3': completeTicket(&first_assigned, &first_completed);
	  break;
	case '4': printList(first_new);
	  break;
	case '5': printList(first_assigned);
	  break;
	case '6': printList(first_completed);
	  break;
	case '7':
	  //since we used malloc, we need to free the memory allocated
	  //in the lists. We created a function to free all the pointers
	  //in a list to do this. 
	  clearList(first_new);
	  clearList(first_assigned);
	  clearList(first_completed);
	  
	  printf ("Program successfully exited\n");
	  
	  return 0;
	  break;
	default: printf ("Invalid Option - Try Again!\n");
	  continue;
	}// switch
    }
  }
}

