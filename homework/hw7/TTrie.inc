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
TTrie<DataType>::TTrie(const TTrie& rhs) {
  isTerminal = rhs.isTerminal;
  sequence = rhs.sequence;
  for(typename map<DataType, TTrie<DataType>*>::const_iterator it = (rhs.edgeMap).cbegin(); it != (rhs.edgeMap).cend(); ++it) {
    DataType key = (it->first);
    TTrie<DataType>* value = (it->second);
    edgeMap[key] = new TTrie(*value);
  }
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
     edgeMap[key] = new TTrie(*value);
   }
   return *this;
}

template<typename DataType>
TTrie<DataType>& TTrie<DataType>::operator+=(const std::vector<DataType>& sequence) {
  if(sequence.empty()) {
//    this->isTerminal = true;
    return *this;
  }
  
  const DataType c = sequence[0];
  const TTrie<DataType>* child = getChild(c);

  if (!child) {
    TTrie<DataType>* n = new TTrie<DataType>(c);
    edgeMap[c] = n;
  }

  if(sequence.size() > 1) {
    typename std::vector<DataType> v;
    typename std::vector<DataType>::const_iterator it;
    it = sequence.cbegin() + 1;
    v.assign(it, sequence.cend());
    *edgeMap[c] += v;
  }
  else {
    edgeMap[c]->isTerminal = true; 
  }
  return *this;
}

template<typename DataType>
bool TTrie<DataType>::operator^(const std::vector<DataType> &sequence) const {
  const TTrie<DataType>* child = getChild(sequence[0]);
  if (child == nullptr) {
    return false;
  }
  
  else {
    if (sequence.size() == 1) {
      return child->isEndpoint();
    }
    else {
      typename std::vector<DataType> v;
      typename std::vector<DataType>::const_iterator it;
      it = sequence.cbegin() + 1;
      v.assign(it, sequence.cend());
      if((*child ^ v) == false) {
        return false;
      } else {
      	 return true;
	 }
    }
  }
  
  return false;
}
  
template<typename DataType>
bool TTrie<DataType>::operator==(const TTrie<DataType>& rhs) const {
  //TTrie<DataType> copiedTTrie = TTrie<DataType>(rhs);
  if(rhs.numChildren() != edgeMap.size()) {
    return false;
  }
  if(rhs.isEndpoint() != this->isEndpoint()) {
    return false;
  }
  for(typename map<DataType, TTrie<DataType>*>::const_iterator it = edgeMap.cbegin(); it != edgeMap.cend(); ++it) {
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

template<typename DataType>
void output_trie(std::vector<DataType>& s,  std::vector<std::vector<DataType>>& v, const TTrie<DataType>& tt){
  if(tt.isEndpoint()) {
    //s.push_back(tt.getSequence());
    //std::string t = tt.getSequence();
    v.push_back(s);
  }
  if(tt.hasChild()) {
    for(typename map<DataType, TTrie<DataType>*>::const_iterator it = tt.edgeMap.cbegin(); it != tt.edgeMap.cend(); ++it) {
      s.push_back(it->first);
      output_trie(s, v, *(it->second));
      s.pop_back();
    }
  }
}

template<typename DataType>
std::ostream& operator<<(std::ostream& os, const TTrie<DataType>& tt) {
  typename std::vector<DataType> s;
  typename std::vector<std::vector<DataType>> returnString;
  output_trie(s, returnString, tt); //would this update returnstring
  std::sort(returnString.begin(), returnString.end());

  //for(std::vector<std::string>::iterator it = returnString.begin(); it != returnString.end(); ++it) {
  for(std::vector<DataType> x : returnString) {
    //for(DataType r : x) {
    for(size_t i = 0; i < x.size(); ++i) {
      os << x[i];
      if (i < x.size() - 1) {
      os << '-';
      }
    }
    os << '\n';
  }
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
  if(edgeMap.find(character) != edgeMap.cend()) {
    return true;
  }
  return false;
}

template<typename DataType>
const TTrie<DataType>* TTrie<DataType>::getChild(const DataType &character) const {
  //typename std::map<char, TTrie<DataType>*>::const_iterator temp = typename edgeMap.find(character);
  if (edgeMap.find(character) != edgeMap.cend()) {
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

template<class DataType>
DataType TTrie<DataType>::getSequence() const {
  return sequence;
}

template class TTrie<int>;
template class TTrie<char>;