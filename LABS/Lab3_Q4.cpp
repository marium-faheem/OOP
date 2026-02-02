#include <iostream>
#include <string>
using namespace std;

class bookType {
private:
    string title;
    string authors[4];     // up to 4 authors
    int numAuthors;        // actual number of authors
    string publisher;
    string ISBN;
    double price;
    int copiesInStock;

public:
    // Constructors
    bookType() {   // default constructor
        title = "";
        numAuthors = 0;
        publisher = "";
        ISBN = "";
        price = 0.0;
        copiesInStock = 0;
    }

    bookType(string t, string auth[], int n, string pub, string isbn, double pr, int copies) {
        title = t;
        numAuthors = n > 4 ? 4 : n;   // max 4 authors
        for (int i = 0; i < numAuthors; i++)
            authors[i] = auth[i];
        publisher = pub;
        ISBN = isbn;
        price = pr;
        copiesInStock = copies;
    }

    // Destructor (not strictly needed here)
    ~bookType() {}

    // Title operations
    void setTitle(string t) { title = t; }
    string getTitle() const { return title; }
    bool isTitle(string t) const { return title == t; }

    // Author operations
    void setAuthors(string auth[], int n) {
        numAuthors = n > 4 ? 4 : n;
        for (int i = 0; i < numAuthors; i++)
            authors[i] = auth[i];
    }
    void showAuthors() const {
        for (int i = 0; i < numAuthors; i++)
            cout << authors[i] << (i < numAuthors - 1 ? ", " : "");
        cout << endl;
    }

    // Publisher operations
    void setPublisher(string pub) { publisher = pub; }
    string getPublisher() const { return publisher; }

    // ISBN operations
    void setISBN(string isbn) { ISBN = isbn; }
    string getISBN() const { return ISBN; }
    bool isISBN(string isbn) const { return ISBN == isbn; }

    // Price operations
    void setPrice(double pr) { price = pr; }
    double getPrice() const { return price; }

    // Copies operations
    void setCopies(int copies) { copiesInStock = copies; }
    int getCopies() const { return copiesInStock; }
    void updateCopies(int change) { copiesInStock += change; }  // positive or negative
};
int main() {
    bookType library[100];  // array of 100 books
    int numBooks = 0;       // current number of books in library

    // Example: add 2 books
    string authors1[] = {"Author A", "Author B"};
    library[numBooks++] = bookType("C++ Basics", authors1, 2, "TechPub", "ISBN001", 500.0, 10);

    string authors2[] = {"Author X"};
    library[numBooks++] = bookType("Python Fundamentals", authors2, 1, "CodeHouse", "ISBN002", 450.0, 5);

    // Search by title
    string searchTitle = "C++ Basics";
    for (int i = 0; i < numBooks; i++) {
        if (library[i].isTitle(searchTitle)) {
            cout << "Book found: " << library[i].getTitle() << endl;
            cout << "Authors: ";
            library[i].showAuthors();
            cout << "Publisher: " << library[i].getPublisher() << endl;
            cout << "ISBN: " << library[i].getISBN() << endl;
            cout << "Price: " << library[i].getPrice() << endl;
            cout << "Copies in stock: " << library[i].getCopies() << endl;
            break;
        }
    }

    // Update copies of a book
    string isbnToUpdate = "ISBN001";
    for (int i = 0; i < numBooks; i++) {
        if (library[i].isISBN(isbnToUpdate)) {
            library[i].updateCopies(5);  // add 5 copies
            cout << "Updated copies: " << library[i].getCopies() << endl;
        }
    }

    return 0;
}

