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

typedef struct phoneNumber {
  string pn_Type;
  string pn_Number;
} phoneNumber;

typedef struct phoneNumberColl {
  vector<phoneNumber> coll;
} phoneNumberColl;

typedef struct cntName {
  string FName;
  string LName;  
} cntName;

string str_to_lower (const string &str) {
  string str2 = str;
  for(int i = 0; i < (int)str.length(); i++) {
    str2[i] = tolower(str[i]);
  }
  return str2;
}

		     
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
  return false;
}

bool numIsValid(const string &pNum) {
  for(int i = 0; i < (int)pNum.length(); i++) {
    if(pNum[i] != '-' && isdigit(pNum[i]) != true) {
      return false;
    }
  }
  return true;
}

      
int main() {

  map<cntName, phoneNumberColl> phone_db;
  cout << "Info: Welcome to the Phone Database!" << endl;
  cout << "Info: Please enter a command" << endl;
  char cmnd;
  //cin >> cmnd;
  while(cin >> cmnd && cmnd != 'Q') {
    switch(cmnd) {
      case 'C': {
	string cFName = "";
	string cLName = "";
	cin >> cFName;
	cin >> cLName;
	cntName cContact = cntName();
	cContact.FName = cFName;
	cContact.LName = cLName;
	//if .find != .end
	
	if (phone_db.find(cContact) != phone_db.end()) {
	  cout << "Error: Contact already exists" << endl;
	}
	else {
	  phone_db[cContact] = phoneNumberColl();
	  cout << "Result: Contact created" << endl;
	}
      }
        break;
      case 'L': {
	for(map<cntName, phoneNumberColl>::iterator it = phone_db.begin(); it != phone_db.end(); ++it) {
	  cout << (it-> first).LName << "," << (it-> first).FName << endl;
	}
      }
        break;
    case 'N': {
	//Declare temp variables and initalize
        string cFName;
        string cLName;
	string cType;
	string cNumber;
        cin >> cFName;
        cin >> cLName;
	cin >> cType;
	cin >> cNumber;
        cntName cContact;
        cContact.FName = cFName;
        cContact.LName = cLName;
	phoneNumber cTotalNum;
	cTotalNum.pn_Type = cType;
	cTotalNum.pn_Number = cNumber;
	//TODO: test to make sure user inputs are correct
	if(phone_db.find(cContact) == phone_db.end()) {
          cout << "Error: Contact not found" << endl;
        }
	else if(cType != "VOIP" && cType != "CELL" && cType != "HOME" && cType != "WORK" && cType != "FAX") {
	  cout << "Error: Invalid phone number type" << endl;
	}
	else if(numIsValid(cNumber) == false) {
	  //TODO: Make invalid
	  cout << "Error: Not a valid phone number" << endl;
	}
	//if((phone_db[cContact]).coll.size() > 0) 
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
	    (phone_db[cContact].coll).push_back(cTotalNum);
	    cout << "Result: Phone number added" << endl;
	  }
	  
	}
	else {
	  (phone_db[cContact].coll).push_back(cTotalNum);
           cout << "Result: Phone number added" << endl;
	}
    }
        break;
    case 'P': {
	//Declare temp variables and initalize
	string cFName;
        string cLName;
        cin >> cFName;
        cin >> cLName;
        cntName cContact;
        cContact.FName = cFName;
        cContact.LName = cLName;

	if (phone_db.find(cContact) == phone_db.end()) {
          cout << "Error: Contact not found" << endl;
        }
	else if((phone_db[cContact]).coll.size() == 0) {
	  cout << "Info: No Phone Numbers have been inputted for this contact" << endl;
	}
        else {
          for(size_t i = 0; i < (phone_db[cContact].coll).size(); i++) {
	    cout << "Result: " << phone_db[cContact].coll[i].pn_Type << "," << phone_db[cContact].coll[i].pn_Number << endl;
	  }
        }
    }
        break;
    case 'D': {
        string cFName;
        string cLName;
        cin >> cFName;
        cin >> cLName;
        cntName cContact;
        cContact.FName = cFName;
        cContact.LName = cLName;
        //if .find != .end

        if (phone_db.find(cContact) == phone_db.end()) {
          cout << "Error: Contact not found" << endl;
        }
        else {
          phone_db.erase(cContact);
          cout << "Result: Contact deleted" << endl;
        }
    }
        break;
    case 'X': {
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

	if(phone_db.find(cContact) == phone_db.end()) {
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
	}
    }
        break;
    case 'S': {
	std::ofstream ofile("data.txt");
	
	for(map<cntName, phoneNumberColl>::iterator it = phone_db.begin(); it != phone_db.end(); ++it) {
          ofile << (it-> first).LName << "," << (it-> first).FName << endl;
        }
	ofile << endl;
	
	for(map<cntName, phoneNumberColl>::iterator it = phone_db.begin(); it != phone_db.end(); ++it) {
	  ofile << (it-> first).LName << "," << (it-> first).FName << endl;
          
	  for(vector<phoneNumber>::iterator it2 = (it-> second).coll.begin(); it2 != (it-> second).coll.end(); it2++) {
	    ofile << it2-> pn_Type << "," << it2-> pn_Number << endl;
	  }
        }
	ofile.close();
    }
        break;
     case 'R':
	//read in first and last, switches at comma or end of for
       istream ifile("data.txt");
       
       phone_db[cContact] = phoneNumberColl();
       break;
    default: {
	cout << "Error: Invalid Command" << endl;
    }
	break;



    }
    cout << "Info: Please enter a command" << endl;
    //cin >> cmnd;
  }
  cout << "Info: Thank you for using the Phone Database!" << endl;
  return 0;
}
