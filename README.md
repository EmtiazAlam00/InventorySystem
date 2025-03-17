**Inventory System**

This project is a inventory system for a store/warehouse, implemented in C++. The application is designed to manage products, their locations in a store and warehouse, and facilitate order fulfillment using object-oriented principles, including inheritance, linked lists, and queues.

**Features**

- **Store Location Management**: The system tracks products available in-store and warehouse locations, supporting FIFO management of warehouse stock.
- **Product Management**: Products can be stored, retrieved, and moved between locations.
- **Queue Management**: Implements a queue to manage warehouse locations and ensure older stock is used first.
- **User Interaction**: A user-friendly interface that allows for product management, including adding stock, removing stock, and fulfilling orders.

  **Class Descriptions**
1. Location (Entity Object)
A base class for representing both StoreLocation and WHLocation. It contains the general attributes and behaviors shared by both types of locations, such as id, product, quantity, and basic methods for adding/removing products.

2. StoreLocation (Entity Object)
Derived from Location, this class represents product locations within the store. It manages the capacity of each store location and provides methods for setting products, adding/removing stock, and checking availability.

3. WHLocation (Entity Object)
Also derived from Location, WHLocation represents warehouse locations for storing products. It accepts "skid" (large packaging) products and supports adding and removing items from warehouse locations.

4. Product (Entity Object)
Represents a product in the inventory system. Each product is associated with a store location and a list of warehouse locations. This class provides methods for adding/removing stock from locations and fulfilling orders.

5. Queue (Container Object)
A FIFO queue that stores warehouse locations. It ensures that older stock is used first when fulfilling orders. It supports adding new locations and removing the first element.

6. List (Container Object)
A sorted list that stores products alphabetically. It provides methods for adding products and finding specific products by name.

7. Store (Control Object)
The Store class manages the store's locations, products, and order fulfillment. It allows users to add products, find available locations, and print store and warehouse stock.

8. Control (Control Object)
This class coordinates interactions between the store and the user. It manages the user interface and invokes the appropriate methods in the Store class.

9. View (View Object)
The view class is responsible for presenting the user interface, gathering user input, and displaying the results.

**UML**

![image](https://github.com/user-attachments/assets/270cbf40-9b06-456f-8912-60a2e973c9cc)
