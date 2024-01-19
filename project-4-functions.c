    /***********************************************************************
     * Name(s) Ella Berman and Jason Kunkel and Giovanna Romero                      *
     * Assignment name: Project 4 (header file)                                      *
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

//prints menu options to screen
//no pre- or post-conditions
void printMenu(void)
{
  printf("Menu options:\n");
  printf("1 - Create a new tracking ticket\n");
  printf("2 - Assign a new ticket to a technician for handling\n");
  printf("3 - Mark a ticket complete\n");
  printf("4 - Print a list of new tickets\n");
  printf("5 - Print a list of assigned tickets\n");
  printf("6 - Print a list of completed tickets\n");
  printf("7 - Exit the program\n");
}

//Pre-condition: first_new points to the pointer designating
// the head of the new ticketlist
//Post-condition: a ticket node is created and added to the end of the new
// ticket list
void createNew(ticket_t ** first_new, int ticketCount)
{
  //create a pointer to a ticket node and allocate space for it
  ticket_t * newTicket = malloc(sizeof(ticket_t));
  int count = ticketCount;
  char company[MAXSTRLEN+1];
  char problem[MAXSTRLEN+1];
  int value = 0; // for checking scanf reading

  //test to see if malloc worked correctly
  if(newTicket == NULL)
  {
    printf("\nNo more memory left: free memory or exit program\n");
    perror("Unable to allocate ticket: ");
    return;
  }

  //Assign ticket information for the new ticket:
  newTicket->ticketNum = count;//assigns ticketNum to be in order
  
  printf("\nEnter company identifier: \n ");
  value = scanf("%s", company);
  
  strcpy(newTicket->company, company);

  printf("\nEnter problem: \n ");
  value = scanf("%s", problem);
  
  strcpy(newTicket->problem, problem);
  
  strcpy(newTicket->status, "new");
  strcpy(newTicket->techName, "unassigned");
  
  ticket_t *cur = *first_new;
  
  //If the current list is empty (*first_new is NULL),
  //assign the newly created ticket to be first
  if (*first_new == NULL) {
    newTicket->next = *first_new;// make newTicket->next point to NULL
    *first_new = newTicket;// make first_new point to the newTicket
  }
  //If the current list is not empty, go through the list until the last
  //ticket node is found and then add newTicket to the end of the list.
   else{
     for(; cur->next != NULL; cur = cur->next)
      {
	// go through list until last ticket is reached
      }
     cur->next = newTicket;//newTicket is pointed to by old last element
     newTicket->next = NULL;//newTicket points to NULL
    }  
}

//assigns the first ticket in the new ticket list to a technician
//Preconditions: pointers to the address of the pointers that point
// to the first elements in the new and assigned lists
//Postconditions: Takes first ticket off new ticket list
// and adds it to the end of assigned ticket list
void assignTicket(ticket_t ** first_new, ticket_t ** first_assigned)
{
  ticket_t * current = *first_new;
  int value = 0; //for error checking scanf
  char techName[MAXSTRLEN+1];
  
  if(*first_new == NULL)
    {
      printf("\nThere are no new tickets to be assigned.\n");
    }
  else
    {
      printf("\nEnter technician name: \n");
      value = scanf("%s", techName);
      
      strcpy(current->techName, techName);
      strcpy(current->status, "assigned");

      *first_new = current->next;
      
      //If the assigned list is empty (*first_assigned is NULL),
      //assign the newly assigned ticket to be first
      if (*first_assigned == NULL) {
	current->next = NULL;// make current->next point to NULL
	*first_assigned = current;// make first_assigned point to the ticket
      }
      //If the assigned list is not empty, go through the list until the last
      //ticket node is found and then add the ticket to the end of the list.
      else
	{
	  ticket_t * cur_assigned = *first_assigned;
	  
	  for(; cur_assigned->next != NULL;
	      cur_assigned = cur_assigned->next)
	    {
	      // go through list until last ticket is reached
	    }
	  cur_assigned->next = current;
	  //assigned ticket is pointed to by old last element
	  current->next = NULL;//assigned ticket points to NULL
	}  
      
    }
}

//prints a ticket list in order
//Preconditions: takes in a pointer to the first element of a ticket list
//Postconditions: traverses the list and prints every element, in order
void printList(ticket_t * firstPtr)
{
  if (firstPtr == NULL){
    printf("\nThere are no tickets in the selected list\n\n");
  }
  else{
    for(; firstPtr != NULL; firstPtr = firstPtr->next)
    {
	printf("\nTicket Number: %d\n", firstPtr->ticketNum);
	printf("Company: %s\n", firstPtr->company);
	printf("Problem: %s\n", firstPtr->problem);
	printf("Status: %s\n", firstPtr->status);
	printf("Name of technician: %s\n\n", firstPtr->techName);
    }
  }    
}

//Precondition: takes in double pointers referencing the addresses
// of the pointers pointing to the first element of the
// assigned and completed ticket lists
//Postcondition: removes ticket to be completed from the assigned list and
// adds it to the end of the completed ticket list
void completeTicket(ticket_t ** first_assigned, ticket_t ** first_completed)
{
  int numMatch = 0;
  bool matched = false;
  ticket_t * current = *first_assigned;
  ticket_t * prev = NULL;
  int value = 0;//for error checking scanf

  //if the assigned ticket list is empty
  if(current == NULL)
    {
      printf("\nThere are no assigned tickets.\n\n");
    }
  else
    {
      printf("Enter a ticket number to mark complete:\n");
      value = scanf("%d", &numMatch);

      //if number is not successfully read, exit function
      if(value != 1)
	{
	  printf("\nError: enter a number\n\n");
	  
	  //gets rid of extraneous characters from buffer
	  //ex. in the case of 'e', where nothing is read, 
	  //and 'e' is leftover
	  while(getchar() != '\n')
	    ;
	  
	  return;//exits function
	}

      //gets rid of extraneous characters from buffer
      //ex. in the case of 1e, where '1' is read, 
      //and 'e' is leftover
      while(getchar() != '\n')
	;

      //if the first ticket in the list
      //is the one being searched for
      if(current->ticketNum == numMatch)
	{
	  *first_assigned = current->next;
	  matched = true;
	  prev = current;
	}
      else
	{
	//if first ticket is not the desired number,
	//search through list to match ticket
	while(current->next != NULL && !matched)
	  {
	    prev = current;
	    current = current->next;
	    
	    if(current->ticketNum == numMatch)
	      {
		matched = true;
	      }
	  }
      }
      //If the whole list was searched without
      //finding a matching ticket number
      if(!matched){
	printf("\nTicket not found\n");
      }
      //if the ticket was found
      else
      {
	prev->next = current->next;
	strcpy(current->status, "completed");
	current->next = NULL;
	  
	ticket_t * cur_completed = *first_completed;
	  
	//If the completed list is empty (*first_completed is NULL),
	//assign the newly completed ticket to be first
	if (*first_completed == NULL)
	{
	  current->next = NULL;// make current->next point to NULL
	  *first_completed = current;
	  // make first_completed point to the ticket
	  }
	  //If the completed list is not empty, go through the list
	  //until the last ticket node is found and then add the ticket to
	  //the end of the list.
	  else
	  {
	    for(; cur_completed->next != NULL;
		  cur_completed = cur_completed->next)
	      {
		  // go through list until last ticket is reached
	      }
	    cur_completed->next = current;
	    //completed ticket is pointed to by old last element
	    current->next = NULL;//completed ticket points to NULL
          }
       }
    }
  }

//Preconditions: takes in a pointer to the first element in a list
//Postconditions: goes through list and clears each pointer in order
//Used at end of program to free memory allocated with malloc
void clearList(ticket_t * firstPtr)
{
  ticket_t * current = firstPtr;

  for(; current != NULL; current = current->next)
    {
      free(current);
    }
  
}

