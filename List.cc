#include <iostream>
#include <string>
using namespace std;

#include "Product.h"
#include "List.h"

//constructor
List::List(): head(NULL){}
//destructor
List:: ~List(){
  Node* currNode = head;
  Node* nextNode = NULL;

  while(currNode!=NULL){
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

int List:: size() const{
  return count;
}

void List::add(Product* prod){
  Node* newNode = new Node();
  newNode->data = prod;
  newNode->next = NULL;

  Node* currNode = head;
  Node* prevNode = NULL;

  while(currNode!=NULL){
    if(newNode->data->getName() < currNode->data->getName()){
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }
  if(prevNode == NULL){
    head = newNode;
  } else{
    prevNode->next = newNode;
  }
  newNode->next = currNode;
}

void List::remove(const string& name, Product** goner){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->getName() == name){
           break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *goner = NULL;
        return;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *goner = currNode->data;
    delete currNode;
}

void List::get(const string& name, Product** prod) {
  Node * currNode = head;

  while (currNode != NULL) {
      if (currNode->data->getName() == name) {
          break;
      }
      currNode = currNode->next;
  }

  *prod = (currNode == NULL) ? NULL : currNode->data;
}

void List::removeUpto(const string& name){
  Node * currNode;
  Node * prevNode;

  currNode = head; //iterating
  prevNode = NULL;

  while (currNode!=NULL){
      if (name < currNode->data->getName()){
          break; 
      }
      prevNode = currNode;
      currNode = currNode->next;
      delete prevNode->data;
      delete prevNode;
  }

  head = currNode;
}

bool List::isEmpty() const{
  return head == NULL;
}

void List::findProduct(const string& name, Product** prod){
  
}

void List::print() const {
  Node* currNode = head;
  if (currNode == NULL) {
      cout << "List is empty." << endl;
      return;
  }
  while (currNode != NULL) {
      currNode->data->print(); // Ensure Product has a `print` method
      currNode = currNode->next;
  }
}