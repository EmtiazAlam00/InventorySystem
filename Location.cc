#include <iostream>
#include <string>
using namespace std;

#include "Location.h"

const string Location:: NONE = "Empty";

Location::Location(char code, int number) {
    id = std::string(1, code) + std::to_string(number);
    product = NONE;
    quantity = 0;
}

bool Location:: isEmpty() const{
    if(quantity == 0) return true;
    return false;
}

bool Location:: isAvailable() const{
    if(product == NONE) return true;
    return false;
}

string Location:: getId() const{
    return id;
}
string Location:: getProduct() const{
    return product;
}

int Location:: getQuantity() const{
    return quantity;
}
void Location:: print() const{
    cout<<"Location class: "<<endl;
    cout<< "Id: "<< getId() <<endl;
    cout<<"Product: "<<getProduct() << endl;
    cout<<"Quantity: "<<getQuantity() << endl;
}

