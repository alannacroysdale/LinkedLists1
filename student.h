#include <iostream>
#include <cstring>

using namespace std;
#ifndef STUDENT_H
#define STUDENT_H

class Student {

    public:

        // Constructor
        Student();
        // Destructor
        ~Student();
        int id;
	string firstname;
	string lastname;
	float gpa;

	int getid();
	string getfirst();
	string getlast();
	float getgpa();

	void setgpa(int newgpa);
	void setfirst(string newfirst);
	void setlast(string newlast);
	void setid(int newid);

	void printstudent();
};

#endif
