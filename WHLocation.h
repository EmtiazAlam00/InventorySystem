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
    int getCapacity() const override;
    bool add(const string& productName, int amount) override;
    bool remove(int amount) override;

    private:
    static const char code;
    static const int capacity;
    static int nextId;

};
#endif
