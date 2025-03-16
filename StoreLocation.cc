#include "StoreLocation.h"
#include "Store.h"
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

// int main() {
//     // Create a store
//     Store myStore("TechMart");

//     // Print initial store state
//     cout << "Initial Store State:" << endl;
//     myStore.print();
//     cout << endl;

//     //Receive products
//     cout << "Receiving 30 iPhones..." << endl;
//     myStore.receiveProduct("iPhone", 30);
//     myStore.printStoreStock();
//     cout << endl;

//     cout << "Receiving 50 MacBooks..." << endl;
//     myStore.receiveProduct("MacBook", 50);
//     myStore.printWareHouseStock();
//     cout << endl;

//     // Attempt to fulfill an order
//     int orderQty = 25;
//     cout << "Fulfilling an order for 25 iPhones..." << endl;
//     myStore.fillOrder("iPhone", orderQty);
//     myStore.printStoreStock();
//     cout << endl;

//     // Check remaining inventory
//     cout << "Current Store Inventory:" << endl;
//     myStore.printProducts();
//     cout << endl;

//     return 0;
// }