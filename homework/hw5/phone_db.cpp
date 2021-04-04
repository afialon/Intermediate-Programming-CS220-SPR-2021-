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
  vector<phoneNumber> coll;
} typedef phoneNumberColl;

struct phoneNumber {
  string pn_Type;
  string pn_Number;
} typedef phoneNumber;

struct cntName {
  string FName;
  string LName;  
} typedef cntName;


      
int main() {
  bool operator<(const cntName &left, const cnt
		 Name &right) {
  // return true if left<right, false otherwise,
    
  // ignoring case
  }

  map<cntName, phoneNumberColl> phone_db;
  cout << "Info: Welcome to the Phone Database!" << endl;
  cout << "Info: Please enter a command" << endl;
  char cmnd;
  cin >> cmnd;
  while(cmnd != 'Q') {
    switch(cmnd) {
      case 'C':
	string cFName;
	string cLName;
	cin >> cFName;
	cin >> cLName;
	cntName cContact;
	cContact.FName = cFName;
	cContact.LName = cLName;
	//if .find != .end
	
	if (phone_db.find(cContact) != phone_db.end) {
	  cout << "Error: Contact already exists" << endl;
	}
	else {
	  phone_db[cContact];
	  cout << "Result: Contact created" << endl;
	}
	
	break;
      case 'L':
	//Do i sort it here?
        break;
      case 'N':
	
        break;
      case 'P':
	
        break;
      case 'D':
        string cFName;
        string cLName;
        cin >> cFName;
        cin >> cLName;
        cntName cContact;
        cContact.FName = cFName;
        cContact.LName = cLName;
        //if .find != .end

        if (phone_db.find(cContact) != phone_db.end) {
          cout << "Error: Contact not found" << endl;
        }
        else {
          phone_db.erase[cContact];
          cout << "Result: Contact deleted" << endl;
        }
	
        break;
      case 'X':
	
        break;
      case 'S':
	
        break;

    



    }

  }

  return 0;
}
