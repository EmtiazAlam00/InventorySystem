#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <string>

using namespace std;

class Location{
    public:
    //constructor
    Location(char code, int number);
    //member functions
    bool isEmpty() const;
    bool isAvailable() const;
    void print() const;

    //virtual member functions implemented by subclass
    virtual int getCapacity() const = 0;
    virtual bool add(const string& prod, int qty)=0;
    virtual bool remove(int qty) = 0; 
    //getters
    string getId() const;
    string getProduct() const;
    int getQuantity() const;

    protected:
    //member variables
    string id;
    string product;
    int quantity;
    static const string& NONE;

};
#endif