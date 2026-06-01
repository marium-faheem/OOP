#include <iostream>
#include <vector>
using namespace std;

class Item {
private:
    int* id;
    string* name;
    float* price;
    bool* inStock;

public:
    // Constructor
    Item(int i = 0, string n = "", float p = 0, bool s = true) {
        id      = new int(i);
        name    = new string(n);
        price   = new float(p);
        inStock = new bool(s);
    }

    // Copy Constructor (Deep Copy)
    Item(const Item& obj) {
        id      = new int(*obj.id);
        name    = new string(*obj.name);
        price   = new float(*obj.price);
        inStock = new bool(*obj.inStock);
    }

    // Destructor
    ~Item() {
        delete id;
        delete name;
        delete price;
        delete inStock;
    }

    // Compare by ID
    bool operator==(const Item& obj) {
        return *id == *obj.id;
    }

    // Compare by Price
    bool operator<(const Item& obj) {
        return *price < *obj.price;
    }

    int getID() {
        return *id;
    }

    void display() {
        cout << "ID: "       << *id
             << " Name: "    << *name
             << " Price: "   << *price
             << " In Stock: "<< *inStock << endl;
    }
};

class Cart {
private:
    vector<Item> items;

public:
    void addItem(Item item) {
        items.push_back(item);
    }

    void removeItem(int id) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i].getID() == id) {
                items.erase(items.begin() + i);
                cout << "Item Removed\n";
                return;
            }
        }
        cout << "Item Not Found\n";
    }

    void findItem(int id) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i].getID() == id) {
                items[i].display();
                return;
            }
        }
        cout << "Item Not Found\n";
    }
};

int main() {
    Cart c;
    Item i1(101, "Mouse", 500, true);
    Item i2(102, "Keyboard", 1200, true);
    c.addItem(i1);
    c.addItem(i2);
    c.findItem(101);
    c.removeItem(102);
    c.findItem(102);
    return 0;
}