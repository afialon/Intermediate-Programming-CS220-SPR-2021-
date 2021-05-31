//Alex Fialon
//afialon1


#include "functions.h"
#include <stdio.h>
#include <string.h>

int read_file(FILE *fp, char words[][MAX_WORD_SIZE + 1], int size) {
  //Skip the line with the size
  //myFile = fopen(
  //Set words length to the size
  words = words[size][MAX_WORD_SIZE + 1];
  assert(size >= 0);
  size_t ssize = (size_t)size;
  char (*w)[size][MAX_WORD_SIZE + 1];
  w = &words;
  int endOf = getc(fp);
  
  //Go to every line in the file
  for(int i = 0; i < size; i++) {
    //
    //Might need to add a catch for blank words
    do{
      //
      char* curWord;
      size_t line_chars;
      getline(&curWord, &line_chars, fp);
      *w[i] = curWord;
      endOf = getc(fp);
    }
    while (endOf != EOF)
  }
  return 1;
  
}

int match(const char *regex, const char *word, int restriction) {
  if (*regex == '\0' && *word == '\0') return 0;
  if (*regex == '\0' && *word != '\0') return 1;
  int regexWoChars = strlen(*regex);
  if(!matchesEnd(regex, word)) {
    return 0;
  }
  for (int i = 0; i < strlen(*regex); i++) {
    if(*regex[i] == '~' || *regex[i] == '*' || *regex[i] == '?') {
      regexWoChars --;
    }
  }
  
  //check for tilde
  int a = 1;
  if (*regex == '~') {
    for (int i = 0; i < restriction + 1; i++) {
      if(match(regex + 1, word, restriction) == 0) {
	return 0;
      }
      if(*word == '\0') {
	return match(regex + 1, word, restriction);
	word++;
      }
    }
    return 1;
  }
  //operate for kleene
  if(*regex[i] == '*') {
    if(i == 0) {
      return 0;
    }
    char beforeReg = *regex[i-1]
    for(int i = 0; i < regexWoChars; i++) {
      if(*word[i] == beforeReg) {
        if(!stillValid(*regex, *word)){
          
        }
      }
    }
  }

  //operate for question mark
  if ((*(regex + 1) == '?') && *regex == *word) {
    if (match (regex + 2, word, restriction) == 1) {
      return match(regex + 2, word + 1, restriction);
    }
    else if(strlen(word) <= restriction) {
      return 1;
    }
    else {
      return 0;
    }
  }

  if (*regex == *word && (*(regex + 1) == '*')) {
    //If next character doesn't match, check further
    if (match(regex, word + 1, restriction != 0)) {
      return match(regex, word + 1, restriction);
    }
    return 0;
  }
  else {
    return match(regex + 2, word, restriction);
  }

  if (*(regex + 1) != '?' && *(regex + 1) != '*' && *(regex + 1) != '~') {
    return 1;
  }
  
  return match(regex + 1, word + 1, restriction);
}

int matchesEnd (const char *regex, const char *word) {
  int i = strlen(regex - 1);
  int j = strlen(word - 1);
  while(*regex[i] == '~' || *regex[i] == '*' || *regex[i] == '?') {
    if(*regex[i] != strlen[j]) {
      return 0;
    }
    else {
      i--;
      j--;
    }
  }
  return 1;
}
