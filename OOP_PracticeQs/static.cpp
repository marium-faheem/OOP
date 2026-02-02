#include <iostream>
using namespace std;

class myClass {
public:
    const int id;          // const must be initialized
    string name;
    static int count;      // static variable to track objects

    // Constructor with initializer list for const id
    myClass(int i) : id(i) {
        count++;
    }

    static int displayCount() {
        return count;
    }
};

// Initialize static variable
int myClass::count = 0;

int main() {
    myClass marium(1);
    myClass memoona(2);
    myClass faheem(3);
    myClass muhammad(4);

    int total_objects = myClass::displayCount(); // Correct call to static function
    cout << "Total objects created: " << total_objects << endl;

    return 0;
}
