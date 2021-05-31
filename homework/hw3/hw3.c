//Alex Fialon
//afialon1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "functions.h"

#define MAX_WORD_NUM 1024
#define MAX_WORD_SIZE 32
#define DEFAULT_RESTRICTION 10

int main(int argc, const char *argv[]) {
  char words[ MAX_WORD_NUM ][ MAX_WORD_SIZE + 1 ]; 
  int tilde_restrict = DEFAULT_RESTRICTION;
  
  //checks input file name
  if (argc < 1) {
    printf("Error: filename unspecified.\n");
    return 1;
  }

  //checks if user inputted a new restriciton
  if (argc > 2) {
    tilde_restrict = atoi(argv[2]);
    //makes sure user input restriction is not out of bounds
    if (tilde_restrict < 1 || tilde_restrict > MAX_WORD_SIZE) {
      printf("Invalid tilde restriction specified.\n");
      return 1;
    }  
  }

  FILE* inf = fopen(argv[1], "r");
  if (inf == NULL) {
    printf("Error: file cannot be opened.\n");
    return 1;
  }



  //Find the number of words in inf
  int num_words;
  fscanf(inf, "%d", &num_words);

  if (read_file(inf, words, num_words) == 1) {
    printf("Error: incorrect number of words specified\n");
    fclose(inf);
    return 1;
  }

}
