#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <cctype>

using std::vector;
using std::string;
using std::map;
using std::cout;
using std::cin;
using std::endl;

struct phoneNumberColl {
  string pn_Type;
  string pn_Number;
}

struct Name {
  string cnt_FName;
  string cnt_LName;  
}

      
int main() {
  map<Name, PhoneNumberColl> phone_db
  //
  cout << "Info: Welcome to the Phone Database!" << endl;
  cout << "Info: Please enter a command" << endl;
  char cmnd;
  cin >> cmnd;
  while(cmnd != 'Q') {
    switch(cmnd) {
      case 'C':
	string cFName;
	string cLName;
	cin >> 
	break;
      case 'L':
	
        break;
      case 'N':
	
        break;
      case 'P':
	
        break;
      case 'D':
	
        break;
      case 'X':
	
        break;
      case 'S':
	
        break;

    



    }

  }

  return 0;
}
