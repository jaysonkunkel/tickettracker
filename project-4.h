    /***********************************************************************
     * Name(s) Ella Berman and Jayson Kunkel and Giovanna Romero                      *
     * Assignment name: Project 4 (header file)                                      *
     *                                                                      *
     * Assignment for 4/28/2023                                             *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *    - referenced the namelist.c lab                                  *
     *   Help obtained                                                     *
     *      Clarification from Barbara and advice from Mae and Ray.                  *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Ella Berman and Jason Kunkel and Giovanna Romero                 *
     ***********************************************************************/
#ifndef __SCHEME_LISTS_H__
#define __SCHEME_LISTS_H__

#define MAXSTRLEN 127

//struct definition
typedef struct ticket ticket_t;

struct ticket{
  int ticketNum;
  char company[MAXSTRLEN+1];
  char problem[MAXSTRLEN+1];
  char status[MAXSTRLEN+1]; //"new", "assigned", "completed"
  char techName[MAXSTRLEN+1];
  ticket_t* next;
};

//function prototypes

//prints menu options to screen
void printMenu(void);

//creates a new ticket and adds it to new ticket list
void createNew(ticket_t ** first_new, int ticketCount);

//prints a ticket list in order
void printList(ticket_t * firstPtr);

//assigns the first new ticket to a technician
void assignTicket(ticket_t ** first_new, ticket_t ** first_assigned);

//searches assigned ticket list for ticket number num
//if found, removes ticket from assigned and adds to end of completed list
void completeTicket(ticket_t ** first_assigned, ticket_t ** first_completed);

//Used at end of program to free memory allocated using malloc
void clearList(ticket_t * firstPtr);

#endif
