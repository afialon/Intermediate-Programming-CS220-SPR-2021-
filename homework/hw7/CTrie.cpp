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


CTrie::~CTrie() {

  for(std::map<char, CTrie*>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it) {
    delete (it-> second);
  }
  edgeMap.clear();
}

CTrie::CTrie(const CTrie& rhs) {
  isWord = rhs.isWord;
  letter = rhs.letter;
  for(map<char, CTrie*>::const_iterator it = (rhs.edgeMap).cbegin(); it != (rhs.edgeMap).cend(); ++it) {
    char key = (it->first);
    CTrie* value = (it->second);
    edgeMap[key] = new CTrie(*value);
  }
}

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
     edgeMap[key] = new CTrie(*value);
   }
   return *this;
}

CTrie& CTrie::operator+=(const std::string& word) {

  if(word.empty()) {
    return *this;
  }
  const char c = word[0];
  const CTrie* child = getChild(c);
    
  if (!child) {
    CTrie* n = new CTrie(c);
    edgeMap[c] = n;
  }

  if(word.size() > 1) {
    //recursively pass the word without the first letter
    std::string w = word.substr(1);
    *edgeMap[c] += w;
  }
  else {
    edgeMap[c]->isWord = true;
  }
  return *this;
}

bool CTrie::operator^(const std::string &word) const {
  const CTrie* child = getChild(word[0]);
  if (child == nullptr) {
    return false;
  }
  else {
    if (word.size() == 1) {
      return child->isEndpoint();
    }
    else {
      std::string w = word.substr(1);
      return *child ^ w;
    }
  }
}

bool CTrie::operator==(const CTrie& rhs) const {
  if(rhs.numChildren() != edgeMap.size()) {
    return false;
  }
  if(rhs.isEndpoint() != this->isEndpoint()) {
    return false;
  }
  for(map<char, CTrie*>::const_iterator it = edgeMap.cbegin(); it != edgeMap.cend(); ++it) {
    if(!(rhs.hasChild(it->first))) {
      return false;//janky?
    }
    else {
      if((*(it->second)== *rhs.getChild(it->first)) == false) {
        return false;
      }
    }
  }
  return true;
    //iterate through the map, compare every node in this map,
    //also looking for extra codes
    //run a quick test to make sure size is equal
}

void output_trie(std::string s,  std::vector<std::string>& v, const CTrie& ct){
  if(ct.isEndpoint()) {    
    //s.push_back(ct.getLetter());//can access in ttrie but not here?
    v.push_back(s);
  }
  for(map<char, CTrie*>::const_iterator it = ct.edgeMap.cbegin(); it != ct.edgeMap.cend(); ++it) {//dont have access to the map here
    output_trie(s + it->first, v, *(it->second));
  }
}


std::ostream& operator<<(std::ostream& os, const CTrie& ct) {
  std::string s;
  std::vector<std::string> returnString;
  output_trie(s, returnString, ct); //would this update returnstring
  std::sort(returnString.begin(), returnString.end());

  //for(std::vector<std::string>::iterator it = returnString.begin(); it != returnString.end(); ++it) {
  for(std::string s : returnString) {
    os << s << '\n';
  }

  return os;
}

unsigned int CTrie::numChildren() const {
  return edgeMap.size();
}
 
bool CTrie::hasChild() const {
  return edgeMap.size() != 0;
}
 
bool CTrie::hasChild(char character) const {
  if(edgeMap.find(character) != edgeMap.cend()) {
    return true;
  }
  return false;
}

const CTrie* CTrie::getChild(char character) const {
  if (edgeMap.find(character) != edgeMap.cend()) {
    return (edgeMap.at(character));
  }
  else {
    return nullptr;
  }
}

bool CTrie::isEndpoint() const {
  return isWord;
}

char CTrie::getLetter() const {
  return letter;
}
