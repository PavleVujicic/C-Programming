#include "defs.h"

/**
 * Initializes the BookClubType structure.
 *
 * @param club Pointer to the BookClubType to be initialized.
 * @param n Pointer to the name of the book club.
 *

 */

void initBookClub(BookClubType *club, char *n){
  strncpy(club->name, n, MAX_STR -1);
  club->name[MAX_STR -1] = '\0';
  initBookArray(&(club->books), ORDER_BY_AUTHOR);
}


/**
 * Function that takes parameters: id, title, authors first and last name, year of
 * publication and rating and then Adds a new book with to the BookClubType.
 *
 * @param club pointer to the BookClubType 
 * @param id int representing the book's id.
 * @param t pointer to the book's title.
 * @param af pointer to the author's first name.
 * @param al pointer to  the author's last name.
 * @param y int  the year of book publication.
 * @param r float the book's rating.
 * @return int C_OK the book is added successfully, or C_NOK any error occurs.
 *
 */

int addBookToClub(BookClubType *club, int id, char *t, char *af, char *al, int y, float r){

  if(id <=0){
    printf("Invalid book id. Id must be greater than 0 ");
    return C_NOK;
  }

  if(y<= 0){
    printf("Invalid book year. Year must be greater than 0 ");
    return C_NOK;
  }

  if(r< 0 || r> 5){
    printf("invalid book rating. Rating must be in range of 0 to 5 ");
    return C_NOK;
  }

  char a[MAX_STR];
  sprintf(a, "%s, %s", al, af);

  BookType *nBook = (BookType *)malloc(sizeof(BookType));
  if(nBook==NULL){
    printf("Memory Allocation Problem -BookType ");
    return C_NOK;
  }

  initBook(nBook, id, t, a, y, r);
  
  if(addBookToArray(&(club->books),nBook)== C_OK){
    
    return C_OK;
  }else{
    free(nBook);
    return C_NOK;
  }
}


/**
 * Prints the book club's name and all the books data information
 *
 * @param club pointer to the BookClubType 
 *
 */

void printBooks(BookClubType *club){
  printf("Book Club Name: %s\n", club-> name);
  printf("All Books:\n");
  printBookArray(&(club->books));
}


/**
 * Prints out the top 20% best-rated books in the given book club’s collection
 *
 * @param club pointer to the BookClubType 
 *
 */

void printTopRatedBooks(BookClubType *club){
  
  BookArrayType allBooks, ratedBooks;

  initBookArray(&allBooks, ORDER_BY_RATING);
  initBookArray(&ratedBooks, ORDER_BY_RATING);

  for(int i=0; i< club->books.size; ++i){
    addBookToArray(&allBooks, club->books.elements[i]);
  }

  int count = (int)(0.2 * allBooks.size);

  for(int i = 0; i < count; ++i){
    addBookToArray(&ratedBooks, allBooks.elements[i]);
  }

  printf("Club Name: %s\n", club->name);
  printf("Top Rated Books: \n");
  printBookArray(&ratedBooks);

  cleanupBookArray(&allBooks);
  cleanupBookArray(&ratedBooks);
}


