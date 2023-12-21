#include "defs.h"

/**
 * Initializes every field of the BookType structure.
 *
 * @param b pointer to the BookType .
 * @param id int representing the book's id
 * @param t pointer to a string representing the book's title.
 * @param a pointer to a string representing the book's author 
 * @param y int representing the year of publication.
 * @param r float representing the book's rating.
 *

 */

void initBook(BookType *b, int id, char *t, char *a, int y, float r){
  b->id =id;
  strncpy(b->title, t, MAX_STR -1);
  b->title[MAX_STR -1] = '\0';
  strncpy(b->author, a, MAX_STR -1);
  b->author[MAX_STR -1] = '\0';
  b->year = y;
  b->rating = r;
}


/**
 * Initializes every field of the  BookArrayType. 
 *
 * @param arr pointer to the BookArrayType 
 * @param o OrderType the sorting order for the book array 
 */

void initBookArray(BookArrayType *arr, OrderType o){
  arr->size= 0;
  arr->order= o;
  for(int i= 0; i< MAX_CAP; ++i){
    arr->elements[i] = NULL;
  }
}


/**
 * Adds a new book to the BookArrayType. Book colection is ordered by the order field.
 *
 * @param arr pointer to the BookArrayType.
 * @param b   pointer to the BookType .
 * @return    returns int C_OK if the book is added successfully, or int C_NOK if any error occurs.
 *
 */

int addBookToArray(BookArrayType *arr, BookType *b){
  if(arr->size >= MAX_CAP){
    
    printf("BookArray has reached Max Capacity");
    
    return C_NOK;
  }

  BookType *book = (BookType *)malloc(sizeof(BookType));
  if(book == NULL){
    
    printf("Memory Allocation Problem -BookType");
    
    return C_NOK;
  }
  initBook(book, b->id, b->title, b->author, b->year, b->rating);

  int insertP;

  if(findInsPt(arr, book, &insertP) == C_OK){
    
    for( int i= arr->size; i> insertP; --i){
      arr->elements[i] = arr->elements[i-1];
    }
    
    arr->elements[insertP] = book;
    arr->size++;
    return C_OK;
  }else{
    printf("ERROR Problem to find position");
    free(book);

    return C_NOK;
  }
}


/**
 * Finds the insert index where a book should be stored into the BookArrayType 
 *
 * @param arr pointer to the BookArrayType.
 * @param b pointer to the BookType .
 * @param insPt pointer to an int where insert index will be stored.
 * @return int C_OK insertion point is found successfully, or C_NOK any error occurs.
 *
 */

int findInsPt(BookArrayType *arr, BookType *b, int *insPt){
  
  int found=0;
  if(arr->order == ORDER_BY_AUTHOR){

    for(int i=0; i<arr->size; ++i){

      if(strcmp(b->author, arr->elements[i]->author)< 0 || (strcmp(b->author, arr->elements[i]->author)== 0 && strcmp(b->title, arr->elements[i]->title)<= 0)){

        *insPt=i;
        found= 1;
        break;
      }
    }

    if(found==0){
      *insPt= arr->size;
    }
    return C_OK;

  }else if(arr-> order == ORDER_BY_RATING){

    for(int i=0; i<arr->size; ++i){
      if(b->rating > arr-> elements[i]-> rating){
        *insPt=i;
        found=1;
        break;
      }
    }
    if(found == 0){
      *insPt=arr->size;
    }
    return C_OK;
  }else{
    return C_NOK;
  }
}


/**
 * Prints all the data for a book.
 *
 * @param pointer b to the BookType .
 *
 */

void printBook(BookType *b){
  printf("%-5d%-40s%-30s%-5d%-4.2f\n", b->id, b->title, b-> author, b-> year, b-> rating);
  
}


/**
 * Prints all data for the books in a BookArrayType. 
 *
 * @param arr pointer to the BookArrayType
 *
*/

void printBookArray(BookArrayType *arr){

  printf("%-5s%-40s%-30s%-5s%-4s\n", "Id", "Title", "Author", "Year", "Rating");

  for(int i=0; i< arr->size; ++i){
    printBook(arr->elements[i]);
    printf("\n");
  }
}


/**
 * Frees the memory allocated in a BookArrayType and set size to 0.
 *
 * @param arr pointer to the BookArrayType 
 */

void cleanupBookArray(BookArrayType *arr){

  for(int i=0; i< arr->size; ++i){
    free(arr->elements[i]);
  }
  arr->size=0;
}


