#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(){
  id = 0;
  firstname = " ";
  lastname = " ";
  gpa = 0;
}

int Student::getid() {
  return id;
}
string Student::getfirst() {
  return firstname;
}
string Student::getlast() {
  return lastname;
}
float Student::getgpa() {
  return gpa;
}

void Student::setgpa(int newgpa) {
  gpa = newgpa;
}
void Student::setfirst(string newfirst) {
  firstname = newfirst;
}
void Student::setlast(string newlast) {
  lastname = newlast;
}
void Student::setid(int newid) {
  id = newid;
}
