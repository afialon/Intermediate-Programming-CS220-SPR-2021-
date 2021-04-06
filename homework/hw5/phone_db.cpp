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
  string left_lastname_lc = str_to_lower(left.LName);
  string right_lastname_lc = str_to_lower(right.LName);
  if (left_lastname_lc < right_lastname_lc) {
    return true;
  }
  if (right_lastname_lc < left_lastname_lc) {
    return false;
  }
  string left_firstname_lc = str_to_lower(left.FName);
  string right_firstname_lc = str_to_lower(right.FName);
  if (left_firstname_lc < right_firstname_lc) {
    return true;
  }
  if (right_firstname_lc < left_firstname_lc) {
    return false;
  }
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
        for(size_t i = 0; i < (phone_db[cContact]).coll.size(); i++) {
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
	phoneNumber cNumber;
	cNumber.pn_Type = cType;
	cNumber.pn_Number = cNumber;
	//TODO: test to make sure user inputs are correct
	if(phone_db.find(cContact) != phone_db.end) {
          cout << "Error: Contact not found" << endl;
        }
	else if(cType != "VOIP" && cType != "CELL" && cType != "HOME" && cType != "WORK" && cType != "FAX") {
	  cout << "Error: Invalid phone number type" << endl;
	}
	else if(numIsInvalid(cNumber) == true) {
	  //TODO: Make invalid
	  cout << "Error: Not a valid phone number" << endl;
	}
	else if((phone_db[cContact]).coll.size() > 0) {
	  int temporaryVal;
	  for(size_t i = 0; i < (phone_db[cContact]).coll.size(); i++) {
	    if((phone_db[cContact].coll[i].pn_Type).compare(cType) == 0) {
	      phone_db[cContact].coll[i].pn_Number = cNumber;
	      temporaryVal = i;
	      cout << "Result: Phone number replaced" << endl;
	      break;
	    }
	  }
	  if((phone_db[cContact].coll[temporaryVal].pn_Type).compare(cType) != 0) {
	    (phone_db[cContact].coll).push_back[cNumber];
	    cout << "Result: Phone number added" << endl;
	  }
	  
	}
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
          for(size_t i = 0; i < (phone_db[cContact].coll).size(); i++) {
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
	//Declare temp variables and initalize
        string cFName;
        string cLName;
        string cType;
        cin >> cFName;
        cin >> cLName;
        cin >> cType;
        cntName cContact;
        cContact.FName = cFName;
        cContact.LName = cLName;

	if(phone_db.find(cContact) != phone_db.end) {
          cout << "Error: Contact not found" << endl;
        }
	else if(cType != "VOIP" && cType != "CELL" && cType != "HOME" && cType != "WORK" && cType != "FAX") {
	  cout << "Error: Invalid phone number type" << endl;
        }
	else if((phone_db[cContact]).coll.size() == 0) {
	   cout << "Info: No numbers exist for this contact" << endl;
	}
	else {
	  int temporaryVal;
          for(size_t i = 0; i < (phone_db[cContact].coll).size(); i++) {
            if((phone_db[cContact].coll[i].pn_Type).compare(cType) == 0) {
	      (phone_db[cContact].coll).erase((phone_db[cContact].coll).begin()+i);
	      temporaryVal = i;
              cout << "Result: Phone number deleted" << endl;
              break;
            }
          }
	  if((phone_db[cContact].coll[temporaryVal].pn_Type).compare(cType) != 0) {
            cout << "Error: No phone number of that type" << endl;
          }
        break;
      case 'S':
	
        break;
      case 'R':

        break;
      default:
	cout << "Error: Invalid Command" << endl;
	break;



    }
    cout << "Info: Please enter a command" << endl;
    cin >> cmnd;
  }
  cout << "Info: Thank you for using the Phone Database!" << endl;
  return 0;
}
