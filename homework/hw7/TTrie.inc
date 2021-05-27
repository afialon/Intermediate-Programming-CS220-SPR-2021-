// TODO: implement TTrie member functions and friend functions
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iterator>
// TODO: add other #includes as needed
#include <algorithm>

using std::map;


// TODO: implement the TTrie member functions and friend functions

template<typename DataType>
TTrie<DataType>::~TTrie() {

  for(typename std::map<DataType, TTrie<DataType>*>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it) {
    delete (it-> second);
  }
  edgeMap.clear();
}

template<typename DataType>
TTrie<DataType>& TTrie<DataType>::operator=(const TTrie<DataType> &rhs) {
   for(typename map<DataType, TTrie<DataType>*>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it) {
     delete (it-> second);
   }
   edgeMap.clear();
   //TODO: Ask TA about correct form
   isTerminal = rhs.isTerminal;
   sequence = rhs.sequence;
   for(typename map<DataType, TTrie<DataType>*>::const_iterator it = (rhs.edgeMap).cbegin(); it != (rhs.edgeMap).cend(); ++it) {
     DataType key = (it->first);
     TTrie<DataType>* value = (it->second);
     edgeMap[key] = value;
     delete value;
   }
   return *this;
}

template<typename DataType>
TTrie<DataType>& TTrie<DataType>::operator+=(const std::vector<DataType>& sequence) {
  if(sequence.empty()) {
    return *this;
  }
  
  const DataType c = sequence[0];
  const TTrie<DataType>* child = getChild(c);

  if (!child) {
    TTrie<DataType>* n = new TTrie<DataType>(c);
    edgeMap[c] = n;
    delete n;
  }

  if(sequence.size() > 1) {
    typename std::vector<DataType> v;
    typename std::vector<DataType>::const_iterator it;
    it = sequence.cbegin() + 1;
    v.assign(it, sequence.cend());
    *edgeMap[c] += v;
  }
  delete child;
  return *this;
}

template<typename DataType>
bool TTrie<DataType>::operator^(const std::vector<DataType> &sequence) const {
  const TTrie<DataType>* child = getChild(sequence[0]);
  if (!child) {
    return false;
    delete child;
  }
  else {
    if (sequence.size() == 1) {
      delete child;
      return true;
    }
    else {
      typename std::vector<DataType> v;
      
      typename std::vector<DataType>::const_iterator it;
      it = sequence.cbegin() + 1;
      v.assign(it, sequence.cend());
      return *child ^ v;
    }
  }
}
  
template<typename DataType>
bool TTrie<DataType>::operator==(const TTrie<DataType>& rhs) const {
  TTrie<DataType> copiedTTrie = TTrie<DataType>(rhs);

  for(typename map<DataType, TTrie<DataType>*>::const_iterator it = edgeMap.cbegin(); it != edgeMap.cend(); ++it) {
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

template<typename DataType>
void output_trie(std::string s,  std::vector<std::string>& v, const TTrie<DataType>& tt){
     if(tt.isEndpoint()) {
    s += tt.sequence;
    v.push_back(s);
  }
  if(tt.hasChild()) {
    for(typename map<DataType, TTrie<DataType>*>::const_iterator it = tt.edgeMap.cbegin(); it != tt.edgeMap.cend(); ++it) {
      output_trie(s, v, *(it->second));
    }
  }
  //char c = 97;
  //while(c <= 122) {
  //  if(tt.hasChild(c)) {
  //    s.push_back(c);
  //    output_trie(s, v, *tt.getChild(c));
  //  }
  // c++;
  //}
}

template<typename DataType>
std::ostream& operator<<(std::ostream& os, const TTrie<DataType>& tt) {
  std::string s;
  std::vector<std::string> returnString;
  output_trie(s, returnString, tt); //would this update returnstring
  std::sort(returnString.begin(), returnString.end());

  //for(std::vector<std::string>::iterator it = returnString.begin(); it != returnString.end(); ++it) {
  for(std::string s : returnString) {
    os << s << "-";
  }
  os << std::endl;
  return os;
}

template<typename DataType>
unsigned int TTrie<DataType>::numChildren() const {
  return edgeMap.size();
}

template<typename DataType>
bool TTrie<DataType>::hasChild() const {
  return edgeMap.size() != 0;
}

template<typename DataType>
bool TTrie<DataType>::hasChild(const DataType &character) const {
  if(edgeMap.find(character) != edgeMap.end()) {
    return true;
  }
  return false;
}

template<typename DataType>
const TTrie<DataType>* TTrie<DataType>::getChild(const DataType &character) const {
  //typename std::map<char, TTrie<DataType>*>::const_iterator temp = typename edgeMap.find(character);
  if (edgeMap.find(character) != edgeMap.end()) {
    return (edgeMap.at(character));
  }
  else {
    return nullptr;
  }
}

template<class DataType>
bool TTrie<DataType>::isEndpoint() const {
  return isTerminal;
} 
 
template class TTrie<int>;
template class TTrie<char>;