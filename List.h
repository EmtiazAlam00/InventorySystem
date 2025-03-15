#ifndef LIST_H
#define LIST_H

#include "Product.h"

class List{

  class Node{
    public:
      Product* data;
      Node* next;
  };
  public:
  int size() const;
  //constructor
  List();
  //destructor
  ~List();
  //member functions
  void add(Product*);
  void get(const string& name, Product**);
  void remove(const string& name, Product**);
  void removeUpto(const string& name);

  bool isEmpty() const;
  void findProduct(const string& name, Product** prod);
  
  void print() const;

  private:
    Node* head;
    int count;
}; 
#endif