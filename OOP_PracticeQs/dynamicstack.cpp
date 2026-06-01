#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    ~Stack() { delete[] arr; }

    bool isFull()
    {
        return top == capacity - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is full!" << endl;
            return;
        }
        top++;
        arr[top] = value;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is already empty!" << endl;
            return;
        }
        top--;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return arr[top];
    }
};

int main(){
    Stack s1(5);
    s1.push(20);
    s1.push(19);
    s1.push(21);
    
    cout << "Top: " << s1.peek() << endl;     
    cout << "Empty? " << s1.isEmpty() << endl; 
    
    s1.pop();
    
    cout << "After pop, top: " << s1.peek() << endl; 
}

