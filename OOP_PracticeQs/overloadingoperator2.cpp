//"[]" operator overloading

#include<iostream>
#include<vector>
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

    friend ostream& operator<<(ostream &output, const Book& b) {
        output << b.name << " by " << b.author;
        return output;
    }
};

class Library {
private:
    string name;
    vector<Book> books;
public:
    Library(string name = "", vector<Book> books = {}) {
        this->name = name;
        this->books = books;
    }

    Book& operator[](int i) {
        return books[i];
    }
};
int main() {

    Book book1("Moby-Dick", "Herman Melville");
    Book book2("1984", "George Orwell");

    Library library("CityLibrary", {book1, book2});

    cout << library[0] << endl;
    cout << library[1] << endl;

    return 0;
}