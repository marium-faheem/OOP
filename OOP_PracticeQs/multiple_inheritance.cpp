#include <iostream>
using namespace std;

// Base class 1
class Academic {
protected:
    int marks;

public:
    void setMarks(int m) {
        marks = m;
    }
};

// Base class 2
class Sports {
protected:
    int score;

public:
    void setScore(int s) {
        score = s;
    }
};

// Derived class (inherits from BOTH classes)
class Result : public Academic, public Sports {
public:
    void showResult() {
        cout << "Academic Marks: " << marks << endl;
        cout << "Sports Score: " << score << endl;
        cout << "Total: " << marks + score << endl;
    }
};

int main() {
    Result obj;

    obj.setMarks(80);
    obj.setScore(15);

    obj.showResult();

    return 0;
}
