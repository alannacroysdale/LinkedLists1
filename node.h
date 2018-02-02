#include <iostream>
#include "student.h"

using namespace std;
#ifndef NODE_H
#define NODE_H

class Node {

    public:

        // Constructor
        Node(Student*);
        // Destructor
        ~Node();
        void setNext(Node* newnext);
        Node* getNext();
	Student* getStudent;
        
    private:
        Student* mystudent;
        Node* next;

};

#endif
