#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
#include <iomanip>
#include "WHLocation.h"

using namespace std;

class Queue{
    //private nested class Node
    class Node{
        public:
        WHLocation* data;
        Node* next;
    };

    public:
    //constructor
    Queue();
    ~Queue();
    //functions
    bool isEmpty() const;
    void peekFirst(WHLocation** loc) const;
    void popFirst(WHLocation** loc);
    void addLast(WHLocation* loc);
    void print() const;
    //int count;
    int size() const;

    private:
    Node* head;
    Node* tail;
    int count;

};
#endif