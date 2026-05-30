#include<iostream>
#include<vector>
using namespace std;

class Item{
    public:
    string name;
    int ID;
    int price;
    bool inStock;

    Item(string n, int id, int p, bool s):name(n),ID(id),price(p),inStock(s){}
    Item(const Item& other){
        ID = other.ID;
        price = other.price;
        name = other.name;
        inStock = other.inStock;
    }
    bool operator==(const Item& other){
        return ID == other.ID;
    }
    bool operator<(const Item& other){
        return price < other.price;
    }
    ~Item(){}
};

class Cart{
    protected:
    vector<Item> items;

    public:
    void addItem(Item item){
        items.push_back(item);
    }
    void removeItem(int id){
        for(auto it = items.begin() ; it != items.end() ; it++){
            if((*it).ID == id){
                items.erase(it);
                break;
            }
        }
    }
    void findItem(int id){
        for(auto& item : items){
            if(item.ID == id){
                cout<<"Item found!"<<endl;
                return;
            }
        }
        cout<<"Item not found!"<<endl;
    }

};

int main(){
    Item item1("Soap",1,50,true);
    Item item2("Shampoo",2,250,true);
    Item item3("Oil",3,120,true);
    Cart myCart;
    myCart.addItem(item1);
    myCart.addItem(item2);
    myCart.addItem(item3);
    myCart.findItem(3);
    myCart.removeItem(1);

    return 0;
}