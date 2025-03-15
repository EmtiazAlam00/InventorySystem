#include <iostream>
#include <string>
using namespace std;
#include "Queue.h"

//Constructor
Queue:: Queue():head(NULL), tail(NULL){ }

int Queue:: size() const{
    return count;
}
//destructor
Queue::~Queue(){
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp; //delete node, but not the WHLocation
    }
    tail = nullptr;
}

bool Queue:: isEmpty() const{
    return head == nullptr;
}

void Queue:: peekFirst(WHLocation** loc) const{
    if(isEmpty()){
        *loc = nullptr;
    } else{
        *loc = head->data;
    }
}

void Queue:: popFirst(WHLocation** loc){
    if(isEmpty()){
        *loc = nullptr;
        return;
    }
    Node* temp = head;
    *loc = head -> data;
    head = head -> next;
    
    if(head == nullptr){
        tail = nullptr;
    }
    delete temp;
}

void Queue::addLast(WHLocation* loc) {
    Node* newNode = new Node();
    
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::print() const {
    Node* currNode = head;
    
    cout << "Queue contents: ";
    
    if (!currNode) {
        cout << "Empty" << endl;
        return;
    }

    while (currNode) {
        cout << "[" << currNode->data->getId() << "] ";
        currNode = currNode->next;
    }
    
    cout << endl;
}