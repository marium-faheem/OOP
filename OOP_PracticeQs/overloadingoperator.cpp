//"<<" ostream operator overloding
#include<iostream>
using namespace std;
class Book {
private:
    string name;
    string author;
public:
    Book(string name = "", string author = "") {
        this->name = name;
        this->author = author;
    }

    friend ostream& operator<<(ostream& output, const Book& b) {
        output << b.name << " by " << b.author << endl;
        return output;
    }
};
int main() {

    Book book("Moby-Dick", "Herman Melville");
    cout << book;

    return 0;
}