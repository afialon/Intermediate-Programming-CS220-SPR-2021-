//Alex Fialon
//afialon1


#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int read_file(FILE *fp, char words[][MAX_WORD_SIZE + 1], int size) {
  //Skip the line with the size
  //Set words length to the size  
  //Go to every line in the file
  for(int i = 0; i < size; i++) {
    if (fscanf(fp, "%s", words[i]) == -1) {
      return 1;
    }
    //Might need to add a catch for blank words
  }
  return 0;
  
}

int match(const char *regex, const char *word, int restriction) {
  if (*regex == '\0' && *word == '\0') {
    return 1;
  }
  
  if (*regex == '\0' && *word != '\0') {
    return 0;
  }
  /*  int regexWoChars = strlen(regex);
  //if(!matchesEnd(regex, word)) {
    //return 0;
    //}
  for (size_t i = 0; i < strlen(regex); i++) {
    if(regex[i] == '~' || regex[i] == '*' || regex[i] == '?') {
      regexWoChars --;
    }
    }*/
  
  //check for tilde
  if (*regex == '~') {
    // How much is beyond the tilde
    
    // int length = post-tilde length
    int length = 0;
    while(*(regex + length) != '\0') {
      length++;
    }
    // Check that post-tilde length isn't too small compared to the restriction
    if(length > 0) {
      return match((regex + length), (word + length), restriction);
    }
    else {
      if(strlen(word) <= (size_t)restriction) {
	return 1;
      }
      else {
	return 0;
      }
    }
    // Is word, starting at word length - length after tilde (or restriction), equivalent?
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
  /*
  //operate for kleene
  if (*regex == '*') {
    for (int i = 0; i < restriction + 1; i++) {
      if (match(regex + 1, word, restriction) == 0) {
	return 0;
      }
      
      if (*word == '\0') {
	return match(regex + 1, word, restriction);
      }
      word++;
    }
    //if none matched above
    return 1;
    }*/

  //operate for question mark
  else if ((*(regex + 1) == '?') && *regex == *word) {
    if (match (regex + 2, word, restriction) == 1) {
      return match(regex + 2, word + 1, restriction);
    }
    else if(strlen(word) <= (size_t)restriction) {
      return 1;
    }
    else {
      return 0;
    }
  }

  else if (*regex == *word && (*(regex + 1) == '*')) {
    //If next character doesn't match, check further
    while (*regex == *word) {
      word++;
    }
  }

  else if (*regex != *word) {
    return 0;
  }
  /*
  if (*(regex + 1) != '?' && *(regex + 1) != '*' && *(regex + 1) != '~' && (*regex == *word) {
    return 1;
    }*/
  
  return match(regex + 1, word + 1, restriction);
}

int matchesEnd (const char *regex, const char *word) {

  


  size_t i = strlen(regex) - 1;
  size_t j = strlen(word) - 1;
  
  while((i != 0 && j != 0)
	&& (regex[i] != '~' ||
	    regex[i] != '*' ||
	    regex[i] != '?')) {
    if(regex[i] != word[j]) {
      return 0;
    }
    else {
      i--;
      j--;
    }
  }
  return 1;
}
