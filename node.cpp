#include <iostream>
#include "Node.h"
#include <iomanip>
#include <stdlib.h>
#include <cstring>

using namespace std;

Node::Node(Student*){
    next = NULL;
}

Node::~Node(){
    delete &mystudent;
    next = NULL;
}

Student* getStudent(){
  Student* s = new Student;
  return s;
}

void Node::setNext(Node* newnext){
    next = newnext;
}

Node* Node::getNext(){
    return next;
}
