//#include <iostream>
#include "Node.h"
#include <iomanip>
#include <stdlib.h>
#include <cstring>

using namespace std;

Node::Node (){
    next = NULL;
    mystudent = new Student;
}

Node::~Node(){
    delete &mystudent;
    next = NULL;
}

Student* Node::getstudent(){
  return mystudent;
}

void Node::setNext(Node* newnext){
    next = newnext;
}

Node* Node::getNext(){
    return next;
}
