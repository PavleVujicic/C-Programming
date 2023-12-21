#Author:

Pavle Vujicic

#Purpose:
Manipulate a collection of books made by different authors, that have been rated from 0-5 by members of a book club.
User can have the option of to print out all the books in the collection at once or print out the top rated books, which are the best 20% percent of the books of the collection.
The user can also add a new book to the collection.  


#list of source code files:
headers:
defs.h
source code:
club.c
books.c
load.c
main.c

#Compilation and Launching instructions:

extract all files to a3 directory.
go into a3
- cd a3
list all files in a3
- ls

To Compile:
gcc -Wall -o a3 main.c load.c club.c books.c

To run:
./a3



