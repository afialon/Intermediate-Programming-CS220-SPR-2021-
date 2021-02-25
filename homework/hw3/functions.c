#include "functions.h"
#include <stdio.h>
#include <string.h>

int read_file(FILE *fp, char words[][MAX_WORD_SIZE + 1], int size) {
  //Skip the line with the size

  //Set words length to the size
  words = words[size][MAX_WORD_SIZE + 1];
  int endOf = getc(fp);
  //Go to every line in the file
  for(int i = 0; i < size; i++) {
    //
    //Might need to add a catch for blank words
    do{
      //
      char[] curWord = 
      words[i] = curWord;
      endOf = getc(fp);
    }
    while (endOf != EOF)
    
  
}

int match(const char *regex, const char *word, int restriction) {
  //
  //
  //
  //
  //
  
}

