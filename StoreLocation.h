#ifndef STORELOCATION_H
#define STORELOCATION_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Location.h"
using namespace std;

class StoreLocation : public Location{
    public:
    StoreLocation();
    //member functions
    void setProduct(const string setsProduct);
    int getFreeSpace() const;

    //Inherited virtual member functions
    virtual int getCapacity() const override;
    virtual bool add(const string& prod, int qty) override;
    virtual bool remove(int amount) override;


    private:
    static const char code = 'A';
    static const int capacity = SLOC_CAPACITY;
    static int nextId;

};
#endif