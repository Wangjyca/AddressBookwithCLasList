#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <string.h>
using namespace std;

class Person // The form for list to assign contact information to its node
{
			public:
			
					char lastname[15];
					char firstname[15];
					char phonenumber[15];
					char address[30];
					//char city[20];
					//char states[10];
					//char zipcode[6];
		 
			Person(){}

			Person(const char* lname, const char* fanme, const char* phnumber,const char* adrs){
						strcpy(lastname,lname);
						strcpy(firstname,fanme);
						strcpy(phonenumber,phnumber);
						strcpy(address,adrs);
			}

			void save(ofstream& of);
			void load(ifstream& inf);
			void display();

			bool operator<(const Person& PersonObj) const
			{
					return true;
			}

		void setvalue(const char* lname, const char* fanme, const char* phnumber,const char* adrs){
						strcpy(lastname,lname);
						strcpy(firstname,fanme);
						strcpy(phonenumber,phnumber);
						strcpy(address,adrs);
			}

};


void Person::save(ofstream& of)
{
		of.write((char *)lastname, sizeof(lastname));
		of.write((char *)firstname, sizeof(firstname));
		of.write((char *)phonenumber, sizeof(phonenumber));
		of.write((char *)address, sizeof(address));
}
 void Person::load(ifstream& inf)
{
		inf.read((char *)lastname, sizeof(lastname));
		inf.read((char *)firstname, sizeof(firstname));
		inf.read((char *)phonenumber, sizeof(phonenumber));
		inf.read((char *)address, sizeof(address));
}

void Person::display()
{
			cout  << lastname <<  "	" << firstname << 
			"	" <<phonenumber<<"	"<< address <<endl;
}

#endif