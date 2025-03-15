
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

// Print all products in the list
void Store::printProducts() {
    cout << "Product List:" << endl;
    products->print();
}


void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = NULL;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==NULL){
        cout<<"Making new product"<<endl;
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);
        prod = new Product(pname, sloc);
        products->add(prod);
        
    }


    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
    }

    cout<<"stocking store location..."<<endl;
    prod->stockStoreLocation();

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