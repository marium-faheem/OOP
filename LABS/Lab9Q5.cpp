#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class DecryptionTechnique {
public:
    // Pure Virtual Function
    virtual void decrypt(string code) = 0;

    // Virtual Destructor
    virtual ~DecryptionTechnique() {}
};

// Derived Class for Technique 1
// Converts ASCII codes back to characters
class DecryptionTechnique1 : public DecryptionTechnique {
public:
    void decrypt(string code) override {

        string decrypted = "";

        // Read ASCII values in groups
        for (int i = 0; i < code.length();) {

            int ascii;

            // Handle 2-digit and 3-digit ASCII values
            if (code[i] == '1') {
                ascii = stoi(code.substr(i, 3));
                i += 3;
            }
            else {
                ascii = stoi(code.substr(i, 2));
                i += 2;
            }

            decrypted += char(ascii);
        }

        cout << "\nTechnique 1 Decryption: " 
             << decrypted << endl;
    }
};

// Derived Class for Technique 2
// Subtracts 2 from ASCII values before conversion
class DecryptionTechnique2 : public DecryptionTechnique {
public:
    void decrypt(string code) override {

        string decrypted = "";

        for (int i = 0; i < code.length();) {

            int ascii;

            // Handle 2-digit and 3-digit values
            if (code[i] == '1') {
                ascii = stoi(code.substr(i, 3)) - 2;
                i += 3;
            }
            else {
                ascii = stoi(code.substr(i, 2)) - 2;
                i += 2;
            }

            decrypted += char(ascii);
        }

        cout << "Technique 2 Decryption: " 
             << decrypted << endl;
    }
};

// Main Function
int main() {

    string code1, code2;

    cout << "Enter Encrypted String for Technique 1: ";
    cin >> code1;

    cout << "Enter Encrypted String for Technique 2: ";
    cin >> code2;

    // Base Class Pointers
    DecryptionTechnique* ptr1;
    DecryptionTechnique* ptr2;

    // Dynamic Memory Allocation
    ptr1 = new DecryptionTechnique1();
    ptr2 = new DecryptionTechnique2();

    // Calling Decrypt Functions
    ptr1->decrypt(code1);
    ptr2->decrypt(code2);

    // Free Memory
    delete ptr1;
    delete ptr2;

    return 0;
}