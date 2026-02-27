#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ------------------- Song Class -------------------
class Song {
private:
    string name;
    string author;
    int length;

public:
    // Constructor
    Song(string name = "", string author = "", int length = 0) {
        this->name = name;
        this->author = author;
        this->length = length;
    }

    // Getter
    int getLength() const {
        return length;
    }

    // Overloaded << operator
    friend ostream& operator<<(ostream& output, const Song& s) {
        output << s.name << " - " << s.author << " -- " << s.length << " min";
        return output;
    }
};

// ------------------- CD Class -------------------
class CD {
private:
    vector<Song> songs;
    int maximumLength;
    int currentLength;

public:
    // Constructor (matches platform style)
    CD(vector<Song> songs = {}, int maximumLength = 0, int currentLength = 0) {
        this->songs = songs;
        this->maximumLength = maximumLength;
        this->currentLength = currentLength;
    }

    // Overloaded += operator
    CD& operator+=(const Song &s) {
        if (currentLength + s.getLength() > maximumLength) {
            cout << "No space available" << endl;
        } else {
            songs.push_back(s);
            currentLength += s.getLength();
        }
        return *this;
    }

    // Overloaded << operator
    friend ostream& operator<<(ostream& o, const CD &cd) {
        for (size_t i = 0; i < cd.songs.size(); i++) {
            o << cd.songs[i] << endl;
        }
        return o;
    }
};

// ------------------- Main Function -------------------
int main() {
    CD novoCD({}, 20, 0);

    Song s1("abrakda25", "bynoone", 12);
    Song s2("eminemmm12", "byeminem8", 6);
    Song s3("newsong", "by558", 7);

    novoCD += s1;  // 12
    novoCD += s2;  // 12 + 6 = 18
    novoCD += s3;  // 18 + 7 = 25 -> exceeds 20

    cout << novoCD;

    return 0;
}