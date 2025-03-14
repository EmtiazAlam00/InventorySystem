#include "WHLocation.h"

using namespace std;

const char WHLocation:: code = 'B';
const int WHLocation:: capacity = WHLOC_CAPACITY;
int WHLocation:: nextId = 0;

//constructor
WHLocation:: WHLocation():Location(code, ++nextId){

}

int WHLocation::getCapacity() const{
    return capacity;
}

bool WHLocation:: add(const string& productName, int amount){
    if(!isAvailable()){
        return false;
    }
    if(amount <= capacity){
        product = productName;
        quantity = amount;
        return true;
    }
    return false;
}

bool WHLocation:: remove(int amount){
    if(amount > quantity){
        return false;
    }
    quantity -= amount;

    if (quantity == 0){
        product = NONE;
    }
    return false;
}