#include <stdio.h>
#include <string.h>

#include "defs.h"
//#include "load.c"
//#include "club.c"
//#include "books.c"

int main()
{
  
  int c;
  BookClubType bookClub;
  char name[MAX_STR] = "Pavle-Book-Club\n";
  initBookClub(&bookClub, name);
  loadBookData(&bookClub);
  system("clear");
  printf("\n");

  do{
    printMenu(&c);

    switch(c){
      case 1:
        printBooks(&bookClub);
        break;

      case 2:
        printTopRatedBooks(&bookClub);
        break;

      case 3: 
        int id, year;
        char title[MAX_STR], firstName[MAX_STR], lastName[MAX_STR];
        float rating;
        char temp;
        
        
          printf("Enter the new book data: \n");
          
        
          printf("Id: ");
          while (scanf("%d", &id) == 0) 
          {
            printf("Please enter valid integer for the Id:");
          
          int c;
          while((c = getchar()) != '\n') {}
          }
          
          printf("Title: ");
          scanf("%c", &temp);
          scanf(" %[^\n]", title);
        
          printf("Author First Name: ");
          scanf("%s", firstName);
        
          printf("Author Last Name: ");
          scanf("%s", lastName);
        
          printf("Year: ");
          
          while (scanf("%d", &year) == 0) 
          {
            printf("Please enter valid integer for the year:");
          
          int cy;
          while((cy = getchar()) != '\n') {}
          }
        
          printf("Rating: ");
          while (scanf("%f", &rating) == 0) 
          {
            printf("Please enter valid float for the rating:");
          
          float cf;
          while((cf = getchar()) != '\n') {}
          }
        

        if(addBookToClub(&bookClub, id, title, firstName, lastName, year, rating) == C_OK){
          printf("Book added successfully!\n");
        }else{
          printf("ERROR: Failed to add book.\n");
        }
        break;

      case 0:
        printf("Exit\n");
        cleanupBookArray(&(bookClub.books));
        break;
      
      default:
        printf("Please enter your selection: ");
    }
  }while(c !=0);

  return 0;
}


void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Print all books\n");
  printf("  (2) Print top rated books\n");
  printf("  (3) Add a book\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}