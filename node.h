//#include <iostream>
#include "student.h"

using namespace std;
#ifndef NODE_H
#define NODE_H

class Node {

    public:

        // Constructor
        Node();
        // Destructor
        ~Node();
        void setNext(Node* newnext);
        Node* getNext();
	Student* getstudent();
        
    private:
        Student* mystudent;
        Node* next;

};

#endif
