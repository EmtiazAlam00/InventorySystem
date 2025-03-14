#include "StoreLocation.h"

const char StoreLocation:: code = 'A';
const int StoreLocation:: capacity;
int StoreLocation:: nextId = 0;

StoreLocation:: StoreLocation():Location(code, ++nextId){

}

void StoreLocation::setProduct(const string setsProduct){
    product = setsProduct;
}

int StoreLocation:: getFreeSpace() const{
    return capacity - quantity;
}

int StoreLocation:: getCapacity() const{
    return capacity;
}

bool StoreLocation:: add(const string& prod, int qty){
    if(product == NONE && qty <= capacity){
        product = prod;
        quantity = qty;
        return true;
    }
    if(product != prod){
        return false;
    }
    if(qty > getFreeSpace()){
        return false;
    }
    quantity += qty;
    return true;
}

bool StoreLocation:: remove(int amount){
    if(amount > quantity){
        return false;
    }
    quantity -= amount;
    return true;
}

