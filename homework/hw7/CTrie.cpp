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
  if(edgeMap.hasChild() && rhs.hasChild()) {
    for(map<char, CTrie>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it) {
      if(rhs[(it->first] == rhs.end() {
	 return false;
      }
	  //can I call straight up size or do I have to specify
      else if(rhs.size() != edgeMap.size()) {
	return false;
      }
      else {
	return (it->second)==(rhs->second);
      }
    }
  }
  else if(!(edgeMap.hasChild()) && !(rhs.hasChild())) {
    delete this;
    //how can I make this function end?
    return true;
  }
  else {
    return false;
  }
      //iterate through the map, compare every node in this map,
      //also looking for extra codes
    //run a quick test to make sure size is equal
} 

friend std::ostream& operator<<(std::ostream& os, const CTrie& ct) {
  string s = "";
  output_trie(os, s, ct);

}

string output_trie(std::ostream& os, std::string s, const CTrie& ct){
  if(ct.isEndpoint()) {
    std::cout << s;
    return s;
  }
  for(map<char, CTrie>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it) {
    s.push_back((this->first));
    output_trie(os, s, (this->second));
  }
}

unsigned numChildren() const {
    return edgeMap.size();
}
 
bool hasChild() const {
  if(edgeMap.empty()) {
    return false;
  }
  return true;
}
 
bool hasChild(char character) const {
  if(edgeMap.find(character) != edgeMap.end()) {
    return true;
  }
  return false;
}

const CTrie* getChild(char character) const {
  if(edgeMap.find(character) != edgeMap.end()) {
    return edgeMap[character];
  }
  else {
    return nullptr;
  }
}

bool isEndpoint() const {
  return isWord;
};