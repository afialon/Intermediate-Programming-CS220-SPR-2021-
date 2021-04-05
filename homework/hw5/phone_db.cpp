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

bool operator<(const cntName &left, const cntName &right) {
  string left_lastname_lc = str_to_lower(left.lastname);
  string right_lastname_lc = str_to_lower(right.lastname)
  if (left_lastname_lc < right_lastname_lc) {
    return true;
  }
  if (right_lastname_lc < left_lastname_lc) {
    return false;
  }

  // TODO: use first names to break ties (because last names
  // are the same)
}

      
int main() {

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
	for(phone_db::iterator it = phone_db.begin(); it != phone_db.end(); ++it) {
	  cout << (it-> first).LName << "," << (it-> first).FName << endl;
	}
        for(size_t i = 0; i < phone_db.size(); i++) {
            cout << "Result: " << phone_db[cContact].coll[i].pn_Type << "," << phone_db[cContact].coll[i].pn_Number << endl;
        }
        break;
      case 'N':
	//Declare temp variables and initalize
        string cFName;
        string cLName;
	string cType;
	string cNumber
        cin >> cFName;
        cin >> cLName;
	cin >> cType;
	cin >> cNumber;
        cntName cContact;
        cContact.FName = cFName;
        cContact.LName = cLName;
	//TODO: test to make sure user inputs are correct
	if(phone_db.find(cContact) != phone_db.end) {
          cout << "Error: Contact not found" << endl;
        }
	else if(cType != "VOIP" && cType != "CELL" && cType != "HOME" && cType != "WORK" && cType != "FAX") {
	  cout << "Error: Invalid phone number type" << endl;
	}
	else if(cNumber
	else {
	  if(
	}
	for(size_t i = 0; i < phone_db.size(); i++)
        break;
      case 'P':
	//Declare temp variables and initalize
	string cFName;
        string cLName;
        cin >> cFName;
        cin >> cLName;
        cntName cContact;
        cContact.FName = cFName;
        cContact.LName = cLName;

	if (phone_db.find(cContact) != phone_db.end) {
          cout << "Error: Contact not found" << endl;
        }
	else if(phone_db.size() == 0) {
	  cout << "No Phone Numbers have been inputted for this contact" << endl;
	}
        else {
          for(size_t i = 0; i < phone_db.size(); i++) {
	    cout << "Result: " << phone_db[cContact].coll[i].pn_Type << "," << phone_db[cContact].coll[i].pn_Number << endl;
	  }
        }
	
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
