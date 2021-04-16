#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
// TODO: add other #includes as needed

#include "CTrie.h"

// TODO: implement the CTrie member functions and friend functions
CTrie& operator=(const CTrie &rhs) {
   for(map<char, CTrie*>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it) {
     delete (it-> second);
   }
   map.clear();
   //TODO: Ask TA about correct form
   CTrie copiedCTire = new CTrie(rhs*);
   //this.isWord = (rhs->isWord);
   //this.letter = (rhs->letter);
   //this.edgeMap =

   this = copiedCTrie;


}

 CTrie& operator+=(const std::string& word) {
   char cLetter = word[0];
   if(word.size() == 0) {
     this-> isWord = true;
   }
   else if(edgeMap.find(cLetter) == edgeMap.end()) {
     edgeMap[cLetter] = CTrie(word);
   }
   else {
     this +=(word + 1);
   }
   return this;
}

bool operator^(const std::string &word) const {
  char cLetter = word[0];
  if(word.size() == 0) {
    return true;
  }
  else if(edgeMap.find(cLetter) == edgeMap.end()) {
    return false;
  }
  else {
    return this ^(word + 1);
  }
}

bool operator==(const CTrie& rhs) const {
  for(map<char, CTrie>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it) {
      //iterate through the map, compare every node in this map,
    if(edgeMap
      //also looking for extra codes
    //run a quick test to make sure size is equal
    //
  }
}

friend std::ostream& operator<<(std::ostream& os, const CTrie& ct) {


}
