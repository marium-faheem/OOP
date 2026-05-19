#include<iostream>
#include<cctype>
using namespace std;
class InvalidPasswordException {
    private :
    string msg;
    public :
    InvalidPasswordException(string m):msg(m){}
    string getMsg(){
        return msg;
    }
};

int main(){
    string username, password;
    bool hasDigit = false;

    try {
        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        // Check password length
        if (password.length() < 6) {
            throw InvalidPasswordException("Password too short(must contain atleast 6 characters)!");
        }

        // Check if password contains a digit
        for (int i = 0; i < password.length(); i++) {
            if (isdigit(password[i])) {
                hasDigit = true;
                break;
            }
        }

        if (!hasDigit) {
            throw InvalidPasswordException("Password must contain atleast 1 digit!");
        }

        cout << "\nLogin Successful!" << endl;
    }
    catch(InvalidPasswordException &e){
        cout<<e.getMsg();
    }
    return 0;
}