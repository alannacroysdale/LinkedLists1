#include <iostream>
#include <vector>
#include <cstring>
#include "Node.h"
#include "student.h"
#include <stdlib.h>
#include <iomanip>

//Alanna Croysdale Linked Lists 2 2-2-18
using namespace std;

void addNode(Node* &firstnode);
void printList(Node* next, Node* firstnode);
void deleteNode(Node* &firstnode);
void averageGPA(Node* firstnode);

int main()
{
    bool repeat = true;
    char input[20];

    Node* firstnode = NULL;

    cout << "Student List\n"
        << "\nEnter 'add' to add a new student, \n"
        << "'print' to display all stored students, \n"
        << "'delete' to remove a student, \n"
        << "'average' to get the average GPA,"
        << " and 'quit' to exit the program." << endl;

    while (repeat == true){

        cout << " >> ";
        cin.get(input, 20);
        cin.ignore(20, '\n');

        if (strcmp(input,"add") == 0){
            addNode(firstnode);
        }
        else if (strcmp(input,"print") == 0){
            printList(firstnode, firstnode);
        }
        else if (strcmp(input,"delete") == 0){
            deleteNode(firstnode);
        }
        else if (strcmp(input, "average") == 0){
            averageGPA(firstnode);
        }
        else if (strcmp(input,"quit") == 0){
            repeat = false;
        }

    }

}

void addNode(Node* &firstnode){
    Node* current = firstnode;

    // If the first node is null, meaning
    // if there are no nodes in the list  
    if (current == NULL){
        firstnode = new Node();
        // prompts the user for inputs to
        // define variables such as name, id and gpa
	cout << "enter the gpa" << endl;
        Student* stu = firstnode->getstudent();
        float finput;
        cin >> finput;
        stu->setgpa(finput);
        cout << "enter the id" << endl;
        int intinput;
        cin >> intinput;
        stu->setid(intinput);
        cout << "enter the first name" << endl;
        string input;
        cin >> input;
        stu->setfirst(input);
        cout << "enter the last name" << endl;
        cin >> input;
        stu->setlast(input);
	}

    // If there is already at least one node in the list
    else { 
        Node* previous = NULL;
        Node* newnode = new Node();
        cout << "enter the gpa" << endl;
        Student* st = newnode->getstudent();
        float finput;
        cin >> finput;
        st->setgpa(finput);
        cout << "enter the id" << endl;
        int intinput;
        cin >> intinput;
        st->setid(intinput);
        cout << "enter the first name" << endl;
        string input;
        cin >> input;
        st->setfirst(input);
        cout << "enter the last name" << endl;
        cin >> input;
        st->setlast(input);

        // first check if it is before first node
        // if it is before the first node, then firstnode 
        // will need to be set again
        if ((newnode->getstudent()->getid()) < (firstnode->getstudent()->getid())){
            // new node is now the first node
            newnode->setNext(firstnode);
            firstnode = newnode;
        }
        // if it equals the first node
        else if ((newnode->getstudent()->getid()) == (firstnode->getstudent()->getid())){
            cout << "There is already a student with that ID.";
        }
        // if it is not before the first node
        else {
            bool set = false;
            while ((current != NULL) && (set == false)){
	      if (current->getstudent()->getid() == newnode->getstudent()->getid()){
                   cout << "There is already a student with that ID.";
                   set = true;
               }
               // check if current node is more than new node
               // if it is, than new node should be placed before
               // current and the while loop exited
	      else if ((current->getstudent()->getid()) > (newnode->getstudent()->getid())){
                   newnode->setNext(current);
                   if (previous != NULL){
                       previous->setNext(newnode);
                   }
                   set = true;
               }
               else {// move along in the loop
                   previous = current;
                   current = current->getNext(); 
               }
            }

            // If the node does not fall in between the other nodes
            // this means the node should fall at the end of the list
            if (set == false){
                newnode->setNext(NULL);
                previous->setNext(newnode);
            }
        }
    }
        
    // for formatting
    cout << endl;
}

void prompt (Node* node) {
        cout << "enter the gpa" << endl;
        Student* stu = node->getstudent();
        float finput;
        cin >> finput;
        stu->setgpa(finput);
        cout << "enter the id" << endl;
        int intinput;
        cin >> intinput;
        stu->setid(intinput);
        cout << "enter the first name" << endl;
        string input;
        cin >> input;
        stu->setfirst(input);
        cout << "enter the last name" << endl;
        cin >> input;
        stu->setlast(input);
}

void printList(Node* next, Node* firstnode){

    // If this is the first time through the recursion
    if (next == firstnode){
        cout << "Students:" << endl << endl;
    }
    // If you haven't reached the end of the list
    if (next != NULL){
      next->getstudent()->printstudent();
        cout << endl;
        // run printList with the next node (recursion)
        printList(next->getNext(), firstnode);
    }
}

void deleteNode(Node* &firstnode){

    // Current starts as the first node
    Node* current = firstnode;
    // Since current starts as the first node, previous is NULL
    Node* previous = NULL;

    char userinput[20];
    int inputID;

    bool studentfound = false;

    // If there is no first node, meaning
    // If there are no nodes in the list
    if (firstnode == NULL){
        cout << "The student list is empty, there is nothing to delete." << endl;
    }
    // If there are nodes in the list
    else {
        cout << "What is the id of the student you'd like to remove? ";
        // Get user input
        cin.get(userinput, 20);
        cin.ignore(20, '\n');
        inputID = atoi (userinput);
        // Search through nodes for one with a matching id
        // While you haven't reached the end of the list, and
        // the requested student hasn't been found
        while ((current != NULL) && (studentfound == false)){
            // Check if the current node matches the requested id
	    if ((current->getstudent()->getid()) == inputID){
                studentfound = true;
                cout << "Student found!" << endl;
                current->getstudent()->printstudent();
            }
            else{
                // If the first node checked matched the request,
                // previous will still be NULL
                // Otherwise, move along the list and set previous to current,
                // and current to next
                // If the end of the list is reached, current will be null, but
                // this is ok, because the rest of the program will be skipped as the
                // requested student wasn't found
                previous = current;
                current = current->getNext();
            }
        }
        // If the student with the specified ID is not found, inform user
        if (studentfound == false){
            cout << "Requested student was not found." << endl;
        }
        // If the student was found
        else {
            cout << "Deleting Student..." << endl;
            // If there was a previous node whose 'next' pointer will need to be changed,
            // now that the node it is pointing is deleted
            if (previous != NULL){
                // Previous should now point to Next, instead of current
                previous->setNext(current->getNext());
                // If there isn't a next node, the getNext should still point to NULL,
                // because the last node of the list is always NULL
            }
            // If there is not a next node, and there is not a previous node
            else if ((current->getNext()) == NULL){
                cout << "The list is now empty." << endl;
                // First node has been deleted, so it should now be NULL
                firstnode = NULL;
            }
            // Delete current
            current->~Node();
        }
    }
    cout << endl;
}

void averageGPA(Node* firstnode){
    Node* current = firstnode;
    // Check if there are nodes in the list
    if (firstnode == NULL){
        cout << "There are no students in the list." << endl;
    }
    else { 
        // define variables
        float sum = 0;
        int n = 0;
        float average;
        // Go through list
        while (current != NULL) {
	  sum += current->getstudent()->getgpa();
            n += 1;
            // Move to the next node
            current = current->getNext();
        }
        // Calculate average
        average = sum/n;
        cout << "Average: " << fixed << setprecision(2) << average << endl; 
    }
    cout << endl;
}
