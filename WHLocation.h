#ifndef WHLOCATION_H
#define WHLOCATION_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Location.h"

using namespace std;

class WHLocation: public Location{
    public:
    //constructor
    WHLocation();
    virtual int getCapacity() const override;
    virtual bool add(const string& productName, int amount) override;
    virtual bool remove(int amount) override;

    private:
    static const char code = 'B';
    static const int capacity = WHLOC_CAPACITY;
    static int nextId;

};
#endif
