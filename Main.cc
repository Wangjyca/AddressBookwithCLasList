#include "Person.h"
#include "Link.h"
#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <string.h>
#include <iomanip>
using namespace std;

	void	readfiletolink(	list<Person> &);
int main() {
  
	Booklist bl; // addressBook list class
 
	do {
							int menuChoice;
							cout << "Please choose one of the options below: " << endl;
							cout << "******************************************************************" << endl;
							cout << "1. Add contact to address book." << endl;
							//cout << "2. Update existing contact." << endl;
							//cout << "3. Delete contact from address book" << endl;
							//cout << "4. Search for contact in address book." << endl;
							cout << "5. List all" << endl;
							cout << "6. Quit the program" << endl;
							cout << "******************************************************************" << endl;
							cout << "Menu number:";
							cin >> menuChoice;
							char findinfo[21];

								switch (menuChoice) {

								case 1: //Function to add contact to address book.
								   bl.setinfo();
									break;
								case 2: //Function to update contact in address book.
						
									break;
								case 3: //Function to delete contact from address book.

									break;
								case 4: //Function to search for contact in address book
						
									break;
 								case 5:  //list all

									bl.readfile();


									break;
								case 6:  //Functiont to quit the program.
									return 0;
								default:
									cin.ignore();
									break;

								}//end of the switch case


		} while (1 == 1);

	return 0;
}