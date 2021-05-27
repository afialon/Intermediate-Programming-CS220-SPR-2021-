#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
// TODO: add other #includes as needed
#include "CTrie.h"
#include <algorithm>


using std::map;

// TODO: implement the CTrie member functions and friend functions
CTrie& CTrie::operator=(const CTrie &rhs) {
  for(map<char, CTrie*>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it) {
    if (it-> second) {
     delete (it-> second);
     }
   }
   edgeMap.clear();
  
   //TODO: Ask TA about correct form
   isWord = rhs.isWord;
   letter = rhs.letter;
   for(map<char, CTrie*>::const_iterator it = (rhs.edgeMap).cbegin(); it != (rhs.edgeMap).cend(); ++it) {
     char key = (it->first);
     CTrie* value = (it->second);
     edgeMap[key] = value;
   }

   return *this;

}

CTrie& CTrie::operator+=(const std::string& word) {
  const char c = word[0];
  const CTrie* child = getChild(c);
    
  if (!child) {
    CTrie* n = new CTrie(c);
    edgeMap[c] = new CTrie(c);
    delete n;
  }

  if(word.size() > 1) {
    *edgeMap[c] += word.substr(1);
  }
  delete child;
  return *this;
}

bool CTrie::operator^(const std::string &word) const {
  const CTrie* child = getChild(word[0]);
  if (!child) {
    return false;
  }
  else {
    if (word.size() == 1) {
      return true;
    }
    else {
      return *child ^ word.substr(1);
    }
  }
}

bool CTrie::operator==(const CTrie& rhs) const {
  CTrie copiedCTrie = CTrie(rhs);
  
  for(map<char, CTrie*>::const_iterator it = edgeMap.cbegin(); it != edgeMap.cend(); ++it) {
    if(!rhs.hasChild(it->first)) {
      return false;//janky?
    }
    else {
      return *(it->second)== *rhs.getChild(it->first);
    }
    
  }
  return true;
      //iterate through the map, compare every node in this map,
      //also looking for extra codes
    //run a quick test to make sure size is equal
}

void output_trie(std::string s,  std::vector<std::string>& v, const CTrie& ct){
  if(ct.isEndpoint()) {
    v.push_back(s);
  }
  if(!(ct.hasChild())) {
    return;
  }
  char c = 97;
  while(c <= 122) {
    if(ct.hasChild(c)) {
      s.push_back(c);
      output_trie(s, v, *ct.getChild(c));
    }
    c++;
  }
}


std::ostream& operator<<(std::ostream& os, const CTrie& ct) {
  std::string s;
  std::vector<std::string> returnString;
  output_trie(s, returnString, ct); //would this update returnstring
  std::sort(returnString.begin(), returnString.end());

  //for(std::vector<std::string>::iterator it = returnString.begin(); it != returnString.end(); ++it) {
  for(std::string s : returnString) {
    os << s << " ";
  }
  os << std::endl;
  return os;
}

unsigned int CTrie::numChildren() const {
  return edgeMap.size();
}
 
bool CTrie::hasChild() const {
  if(edgeMap.empty()) {
    return false;
  }
  return true;
}
 
bool CTrie::hasChild(char character) const {
  if(edgeMap.find(character) != edgeMap.end()) {
    return true;
  }
  return false;
}

const CTrie* CTrie::getChild(char character) const {
  std::map<char, CTrie*>::const_iterator temp = edgeMap.find(character);
  if (temp != edgeMap.end()) {
    return (temp->second);
  }
  //if(edgeMap.find(character) != edgeMap.end()) {
  //const CTrie* temp = edgeMap[character];
  //return temp;
  //}
  else {
    return nullptr;
  }
}

bool CTrie::isEndpoint() const {
  return isWord;
}

CTrie* CTrie::createWord (const std::string word) const {
  std::cout << "creating word for word: " << word << std::endl;
    if(word.empty()) {
      CTrie cCTrie = CTrie();
      CTrie* nCTrie = &cCTrie;
      return nCTrie;
    }
    else if(word.length() == 1) {
      CTrie cCTrie = CTrie(word[0], true);
      CTrie* nCTrie = &cCTrie;
      return nCTrie;
    }
    else {
      //Create a new node for the first letter
      char cLetter = word[0];
      CTrie cCTrie = CTrie(cLetter);
      //is this a natural construction
      //initially word + 1
      CTrie* nCTrie = createWord(word.substr(1));
      cCTrie.edgeMap[word[1]] = nCTrie;
      //Recursively call for the rest of the word
      CTrie* pCTrie = &cCTrie;
      return pCTrie;
    }
  }
