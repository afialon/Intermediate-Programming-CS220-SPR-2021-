#ifndef CTRIE_H
#define CTRIE_H

#include <map>
#include <vector>
#include <string>


class CTrie {
public:
  /**
   * Default Constructor.
   */
  //What do i put in here for map
  CTrie(): isWord(false), char(''), edgeMap(std::map<char, CTrie*>) { } ;

  /**
   * Copy Constructor.
   * \param rhs A const reference to the input to copy.
   */
  //TODO: Create Deep Copy
  CTrie(const CTrie& rhs): isWord(rhs.isWord), letter(rhs.letter), edgeMap(rhs.edgeMap) { };

  /**
   * Destructor.
   */
  //recursively deletes all of objects children then o
  //iterates through the map, deletes all children, deletes map, then other parameters
  ~CTrie() {
    for(map<char, CTrie*>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it) {
      delete (it-> second);
    }
    map.clear();
    delete this;
  };

  /**
   * Assignment operator.
   */
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
    

  };

  /**
   * Overloaded addition/assignment operator to input a new string into the Trie.
   * \param word is the word to input into the operator.
   * \return a reference to the CTrie object
   */
  CTrie& operator+=(const std::string& word) {
    char cLetter = word[0];
    edgeMap[cLetter]+= 
      std::string cWord = word;
      
      this +=(word*);
    }
    else {
      //Create nodes for the rest of the word's letters
    }    for(map<char, CTrie*>::iterator it = edgeMap.begin(); it != edgeMap.end(); ++it) {
      if((it->first) = 
    }
  };

  /**
   * Overloaded carat operator to check whether a given word exists in the object.
   * \param word the word to find.
   * \return true if the word is a member of the trie, false otherwise
   */
  bool operator^(const std::string &word) const {
    
  };

  /**
   * Overloaded equality operator to check whether two Trie objects are equal.
   * \param rhs A const reference to the CTrie object to compare.
   * \return true if the other object represents exactly the same set of words,
   *         false otherwise
   */
  bool operator==(const CTrie& rhs) const;

  /**
   * \brief Overloaded output stream operator<< to print the CTrie in 
   * this format a word by line in alphabetical order
   *   e.g. if we have a CTrie with three words 'johns', 'hopkins', 'university'
   *    it will print "hopkins\njohns\nuniversity\n"
   * \param os A reference to the output stream object
   * \param q A constant reference to the input CTrie object
   * \return A reference to the output stream object
  */
  friend std::ostream& operator<<(std::ostream& os, const CTrie& ct) {
    

  };

  /**
   * \return the number of children
   */
  unsigned numChildren() const ;

  /**
   * \return true if there are any children, false otherwise
   */
  bool hasChild() const;

  /**
   * Check whether a child linked by a specific character exists.
   * \param character a character
   * \return true if there is a link to a child labeled with the character,
   *         false otherwise
   */
  bool hasChild(char character) const;

  /**
   * Get pointer to child node reachable via link labeled with
   * the specified character.
   * \param character a character
   * \return pointer to child node, or nullptr if there is no such child
   */
  const CTrie* getChild(char character) const;

  /**
   * \return true if this node is an endpoint, false otherwise
   */
  bool isEndpoint() const; 

private:
  // TODO: fields
  //is true if the word is complete, and is false if not
  bool isWord;
  const char letter;
  //This map contains up to 26 values, each of which is represented by an actual letter and the edge to the node representing that SPECIFIC letter
  std::map<char, CTrie*> edgeMap;
  
  
  // TODO: helper functions
};

#endif // CTRIE_H
