#ifndef LINK_H
#define LINK_H

#include "Person.h"   //// for list to assign contact information to its node
#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <string.h>
using namespace std;

class Booklist{  //To manage all information operation
public:
string filename;
Person contactInfo;
list<Person> theBList;

   	Booklist(){
		 filename="Addressbook.dat";}

		Booklist(string nameoffile){filename=nameoffile; }
		
	
		void readfile();
		void writefile();
		void setinfo();

};



			void Booklist::readfile() {
				  
					ifstream Readmyfile; // The file will be load information to list
					Readmyfile.open(filename, ios::binary | ios::out);
						theBList.clear();// reset list before read info from file
								cout << "--Loading---------------------------------"<< endl;
						while (!Readmyfile.eof()) {
								contactInfo.load(Readmyfile); // read one line data
								if (!Readmyfile.eof()) 
								theBList.push_back(contactInfo); // push contact information in list
						}
					Readmyfile.close();
				   	list<Person>::iterator it;
							cout << "File readed!" << endl<< endl;
						for(it=theBList.begin(); it != theBList.end(); ++it) {
							cout << it->lastname << "\t" << it->firstname << "\t" 
							     << it->phonenumber << "\t" << it->address <<"\n";
						}

							cout << "--End-----------------------------------"<< endl;
			}

			void Booklist::writefile() {
				  list<Person>::iterator it;

					ofstream myfile; // The file will be save information to 
					myfile.open(filename,  ios::binary |ios::out);;
												for(it=theBList.begin(); it != theBList.end(); ++it) {
													          	contactInfo.setvalue(	it->lastname,
																			 											it->firstname,
																														it->phonenumber,
																			 											it->address);
																			contactInfo.save(myfile);
												}
					myfile.close();
							cout << "--File written!------------------------" << endl;
			}

			void Booklist::setinfo(){ // for user to input information 
				char exitkey='Y'; //to confirm if the user wants to exit the Add contact function
				char firstnamestring[15], lastnamestring[15], phonestring[15], streetstring[30];//, citystring[20], zipstring[5];	

				while (1==1)
				{
					cout << "-----------Enter new contact information: -------------" <<endl;
					cin.ignore();
					cout <<"First Name: "; cin.getline(firstnamestring, 15);
					cout <<"Last Name: "; cin.getline(lastnamestring, 15);
					cout <<"Phone Number: "; cin.getline(phonestring, 15);
					cout <<"address street: "; cin.getline(streetstring, 30);
					
						contactInfo.setvalue(firstnamestring,lastnamestring,phonestring,streetstring); // send infomation to contactInfo of class person 
						theBList.push_back(contactInfo);

					cout << "Do want to continue (Y/N) ?";
					cin >> exitkey;
					if (exitkey=='N') break;
				}

				writefile();// to save information to file
			}


#endif


