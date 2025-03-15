#include "Store.h"

//Constructor
Store::Store(const string& name) : name(name) {
    products = new List();
}

//destructor
Store:: ~Store() {
    delete products;
}

void Store:: findAvailableSLoc(StoreLocation** sloc){
    for(int i = 0; i < SLOCS; ++i){
        if(storeLocations[i].isAvailable()){
            *sloc = &storeLocations[i];
            return;
        }
    }
    *sloc = nullptr;
}

void Store:: findAvailableWHLoc(WHLocation** wloc){
    for(int i = 0; i < WHLOCS; ++i){
        *wloc = &whLocations[i];
        return;
    }
    *wloc = nullptr;
}

void Store:: findProduct(const string& name, Product** prod){
    products->findProduct(name, prod);
}

// Print all store stock locations with products assigned
void Store::printStoreStock() {
    cout << "Store Stock:" << endl;
    for (int i = 0; i < SLOCS; ++i) {
        if (!storeLocations[i].isAvailable() || storeLocations[i].getQuantity() > 0) {
            storeLocations[i].print();
        }
    }
}

// Print all warehouse locations that are not empty
void Store::printWareHouseStock() {
    cout << "Warehouse Stock:" << endl;
    for (int i = 0; i < WHLOCS; ++i) {
        if (!whLocations[i].isAvailable()) {
            whLocations[i].print();
        }
    }
}

void Store::printProducts() {
    cout << "Product List:" << endl;
    if (products->isEmpty()) {
        cout << "No products found." << endl;
    } else {
        cout << "Number of products: " << products->size() << endl; // Assuming List has a `size` method
        products->print();
    }
}

void Store::receiveProduct(const string& pname, int quantity) {
    cout << "Receiving product: " << pname << " (" << quantity << " units)" << endl; // Debug statement
    Product* prod = nullptr;
    products->findProduct(pname, &prod);
    if (prod == nullptr) {
        cout << "Creating new product: " << pname << endl; // Debug statement
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);
        prod = new Product(pname, sloc);
        products->add(prod);
    }
    cout << "Adding " << quantity << " units of " << pname << " to warehouse locations." << endl; // Debug statement
    WHLocation* bloc;
    while (quantity > 0) {
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()) {
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        } else {
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
    }
    cout << "Stocking store location for " << pname << endl; // Debug statement
    prod->stockStoreLocation();

    // Debug: Print the products list after adding a new product
    cout << "Products list after adding " << pname << ":" << endl;
    products->print();
}
void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == NULL){
        return;
    }
    prod->fillOrder(quantity);
}


void Store::print(){
    cout<<"Store: "<<name<<endl;
}