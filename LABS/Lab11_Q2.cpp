#include<iostream>
#include<vector>
#include<string>
#include<algorithm>  // For std::reverse
using namespace std;

class Stack{
private:
    vector<string> data;  // Store strings (words), not chars
    
public:
    Stack() {}  // Empty constructor (no parameters needed)
    
    // PUSH - add element to stack
    void push(string element) {  // Takes STRING, not char!
        data.push_back(element);
        cout << "Pushed: " << element << "\n";
    }
    
    // POP - remove element from stack
    void pop() {
        if (data.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped: " << data.back() << "\n";
        data.pop_back();
    }
    
    // PEEK - view top element without removing
    string peek() {  // Should RETURN the top element!
        if (data.empty()) {
            cout << "Stack is empty!\n";
            return "";
        }
        return data.back();
    }
    
    // CHECK if empty
    bool isEmpty() {  // Should RETURN a bool!
        return data.empty();
    }
    
    // REVERSE words in sentence
    string reverseWords(string sentence) {
        string result = "";
        string word = "";
        
        for (char c : sentence) {
            if (c == ' ') {
                std::reverse(word.begin(), word.end());
                result += word + " ";
                word = "";
            } 
            else {
                word += c;
            }
        }
        
        if (!word.empty()) {
            std::reverse(word.begin(), word.end());
            result += word;
        }
        
        return result; 
    }
    
    // DISPLAY stack
    void display() {
        cout << "Stack: ";
        for (string s : data) {
            cout << s << " ";
        }
        cout << "\n";
    }
};

int main(){
    Stack s;
    
    cout << "===== DYNAMIC STACK =====\n\n";
    
    // PUSH elements
    cout << "Pushing elements:\n";
    s.push("Marium");
    s.push("Faheem");
    s.push("Memoona");
    
    s.display();
    cout << "\n";
    
    // PEEK
    cout << "Top element: " << s.peek() << "\n\n";
    
    // POP
    cout << "Popping:\n";
    s.pop();
    s.pop();
    
    s.display();
    cout << "\n";
    
    // REVERSE WORDS
    cout << "Reversing sentence:\n";
    string sentence = "Marium Faheem";
    cout << "Original: " << sentence << "\n";
    cout << "Reversed: " << s.reverseWords(sentence) << "\n";
    
    return 0;
}