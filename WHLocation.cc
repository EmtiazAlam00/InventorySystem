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

// bool WHLocation:: add(const string& productName, int amount){
//     if(!isAvailable()){
//         return false;
//     }
//     if(amount <= capacity){
//         product = productName;
//         quantity = amount;
//         return true;
//     }
//     return false;
// }

bool WHLocation::add(const string& productName, int amount) {
    if (quantity + amount > capacity) {
        return false;
    }
    if (quantity == 0) {
        product = productName;
    }
    quantity += amount;
    return true;
}
// bool WHLocation::add(const string& productName, int amount){
//     // Debugging output
//     cout << "Trying to add " << amount << " of " << productName << " to WHLocation: " << id << endl;
//     cout << "Current product: " << product << ", Current quantity: " << quantity << endl;

//     // If the location already has a product but it's a different one, reject
//     if (quantity > 0 && product != productName) {
//         cout << "Failed: Different product already exists!" << endl;
//         return false;
//     }

//     // If the addition exceeds capacity, reject
//     if (quantity + amount > capacity) {
//         cout << "Failed: Exceeds capacity!" << endl;
//         return false;
//     }

//     // If adding a new product, set its name
//     if (quantity == 0) {
//         product = productName;
//     }

//     // Add the quantity
//     quantity += amount;
//     cout << "Success: Added!" << endl;
//     return true;
// }

bool WHLocation:: remove(int amount){
    if(amount > quantity){
        return false;
    }
    quantity -= amount;

    if (quantity == 0){
        product = NONE;
    }
    return true;
}


//main

// int main() {
//     // Create a WHLocation object
//     WHLocation whLoc;

//     // Print initial state
//     cout << "Initial Warehouse Location State:" << endl;
//     whLoc.print();
//     cout << "Capacity: " << whLoc.getCapacity() << endl;
//     cout << endl;

//     // Attempt to add a product within capacity
//     cout << "Adding 30 Laptops to warehouse location..." << endl;
//     if (whLoc.add("Laptops", 30)) {
//         cout << "Added successfully!" << endl;
//     } else {
//         cout << "Failed to add!" << endl;
//     }
//     whLoc.print();
//     cout << endl;

//     // Attempt to remove some quantity
//     cout << "Removing 10 Laptops from warehouse location..." << endl;
//     if (whLoc.remove(10)) {
//         cout << "Removed successfully!" << endl;
//     } else {
//         cout << "Failed to remove!" << endl;
//     }
//     whLoc.print();
//     cout << endl;

//     // Attempt to over-remove more than available stock
//     cout << "Trying to remove 30 Laptops (more than available)..." << endl;
//     if (whLoc.remove(30)) {
//         cout << "Removed successfully!" << endl;
//     } else {
//         cout << "Failed to remove due to insufficient stock!" << endl;
//     }
//     whLoc.print();
//     cout << endl;

//     // Attempt to add a product exceeding capacity
//     cout << "Trying to add 50 Desktops (exceeds capacity)..." << endl;
//     if (whLoc.add("Desktops", 50)) {
//         cout << "Added successfully!" << endl;
//     } else {
//         cout << "Failed to add due to capacity limit!" << endl;
//     }
//     whLoc.print();
//     cout << endl;

//     return 0;
// }
