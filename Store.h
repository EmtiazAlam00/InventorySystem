
#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Product.h"
#include "List.h"
#include "defs.h"
#include "StoreLocation.h"
#include "WHLocation.h"


using namespace std;

class Store {
		
	public:
		//constructor
		Store(const string& name);
		
		//destructor
		~Store();

		//other
		void findAvailableSLoc(StoreLocation**);
		void findAvailableWHLoc(WHLocation**);
		void findProduct(const string& name, Product** prod);


		void printStoreStock();
		void printWareHouseStock();
		void printProducts();

		//these are done for you
		void receiveProduct(const string&, int quantity);
		void fillOrder(const string&, int &quantity);
		void print();
	
	private:
		string name;
		StoreLocation storeLocations[SLOCS]; // statically allocated array
		WHLocation whLocations[WHLOCS]; //statically allocated array
		List* products;
		
	
};
#endif