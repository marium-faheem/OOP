#include <iostream>
using namespace std;

// Base Media class
class Media {
protected:
    string title;
    int id;
    bool isBorrowed;
public:
    Media(string t, int i) : title(t), id(i), isBorrowed(false) {}

    virtual void display() {
        cout << "ID: " << id << "\nTitle: " << title
             << "\nStatus: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }

    void borrowMedia() {
        if (isBorrowed)
            cout << title << " is already borrowed!" << endl;
        else {
            isBorrowed = true;
            cout << title << " borrowed successfully!" << endl;
        }
    }

    void returnMedia() {
        if (!isBorrowed)
            cout << title << " was not borrowed!" << endl;
        else {
            isBorrowed = false;
            cout << title << " returned successfully!" << endl;
        }
    }
};

// BookAttributes
class BookAttributes {
protected:
    string author, isbn;
public:
    BookAttributes(string a, string i) : author(a), isbn(i) {}
};

// MagazineAttributes
class MagazineAttributes {
protected:
    int issueNumber;
    string publisher;
public:
    MagazineAttributes(int iss, string pub) : issueNumber(iss), publisher(pub) {}
};

// DVDAttributes
class DVDAttributes {
protected:
    string director;
    int duration; // in minutes
public:
    DVDAttributes(string d, int dur) : director(d), duration(dur) {}
};

// Book - inherits Media + BookAttributes
class Book : public Media, public BookAttributes {
public:
    Book(string t, int i, string a, string isbn)
        : Media(t, i), BookAttributes(a, isbn) {}

    void display() override {
        Media::display();
        cout << "Author: " << author << "\nISBN: " << isbn << endl;
    }
};

// Magazine - inherits Media + MagazineAttributes
class Magazine : public Media, public MagazineAttributes {
public:
    Magazine(string t, int i, int iss, string pub)
        : Media(t, i), MagazineAttributes(iss, pub) {}

    void display() override {
        Media::display();
        cout << "Issue Number: " << issueNumber << "\nPublisher: " << publisher << endl;
    }
};

// DVD - inherits Media + DVDAttributes
class DVD : public Media, public DVDAttributes {
public:
    DVD(string t, int i, string d, int dur)
        : Media(t, i), DVDAttributes(d, dur) {}

    void display() override {
        Media::display();
        cout << "Director: " << director << "\nDuration: " << duration << " mins" << endl;
    }
};

int main() {
    Book b("The Alchemist", 101, "Paulo Coelho", "978-0062315007");
    Magazine mag("National Geographic", 202, 45, "Nat Geo Publishers");
    DVD dvd("Inception", 303, "Christopher Nolan", 148);

    cout << "===== Book =====" << endl;
    b.display();
    b.borrowMedia();
    b.borrowMedia(); // try borrowing again
    b.returnMedia();

    cout << "\n===== Magazine =====" << endl;
    mag.display();
    mag.borrowMedia();
    mag.returnMedia();

    cout << "\n===== DVD =====" << endl;
    dvd.display();
    dvd.borrowMedia();
    dvd.returnMedia();

    return 0;
}