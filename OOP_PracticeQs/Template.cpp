#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
    public:
        T1 first;
        T2 second;

        Pair(T1 a, T2 b) {
            first = a;
            second = b;
        }

        void display() {
            cout << "First: " << first << ", Second: " << second << "\n";
        }
};

int main() {
    Pair<string, int> person("Alice", 20);      // name + age
    Pair<int, double> score(1, 9.5);            // rank + GPA

    person.display();   // Output: First: Alice, Second: 20
    score.display();    // Output: First: 1, Second: 9.5

    return 0;
}