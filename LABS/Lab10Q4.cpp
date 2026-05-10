#include <iostream>
using namespace std;

// Abstract Class Template for 1D Dynamic Array
template <class T>
class DynamicArray {
protected:
    T* arr;
    int capacity;

public:
    DynamicArray(int size = 5) {
        capacity = size;
        arr = new T[capacity];
    }

    // Pure Virtual Functions
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual T Front() = 0;
    virtual T Rear() = 0;
    virtual void enqueue(T value) = 0;
    virtual void dequeue() = 0;
    virtual void resize() = 0;

    // Destructor
    virtual ~DynamicArray() {
        delete[] arr;
    }
};

// Dynamic Queue Class
template <class T>
class DynamicQueue : public DynamicArray<T> {

private:
    int front;
    int rear;
    int count;

public:

    // Constructor
    DynamicQueue(int size = 5) : DynamicArray<T>(size) {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Check if Queue is Full
    bool isFull() {
        return count == this->capacity;
    }

    // Check if Queue is Empty
    bool isEmpty() {
        return count == 0;
    }

    // Return current size
    int size() {
        return count;
    }

    // Return Front Element
    T Front() {
        if (!isEmpty())
            return this->arr[front];

        cout << "Queue is Empty!" << endl;
        return T();
    }

    // Return Rear Element
    T Rear() {
        if (!isEmpty())
            return this->arr[rear];

        cout << "Queue is Empty!" << endl;
        return T();
    }

    // Resize Queue
    void resize() {

        int newCapacity = this->capacity * 2;

        T* temp = new T[newCapacity];

        // Copy elements
        for (int i = 0; i < count; i++) {
            temp[i] = this->arr[(front + i) % this->capacity];
        }

        delete[] this->arr;

        this->arr = temp;

        front = 0;
        rear = count - 1;

        this->capacity = newCapacity;

        cout << "Queue Resized to Capacity = "
             << this->capacity << endl;
    }

    // Enqueue Function
    void enqueue(T value) {

        if (isFull()) {
            resize();
        }

        rear = (rear + 1) % this->capacity;

        this->arr[rear] = value;

        count++;

        cout << value << " inserted into queue." << endl;
    }

    // Dequeue Function
    void dequeue() {

        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << this->arr[front]
             << " removed from queue." << endl;

        front = (front + 1) % this->capacity;

        count--;
    }

    // Display Queue
    void display() {

        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue Elements: ";

        for (int i = 0; i < count; i++) {
            cout << this->arr[(front + i) % this->capacity]
                 << " ";
        }

        cout << endl;
    }
};

int main() {

    // Create Dynamic Queue
    DynamicQueue<int> q(5);

    // Enqueue Elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    // Queue becomes full -> resize
    q.enqueue(6);

    q.display();

    // Dequeue Elements
    q.dequeue();
    q.dequeue();

    q.display();

    // Front and Rear
    cout << "Front Element: " << q.Front() << endl;
    cout << "Rear Element: " << q.Rear() << endl;

    // Queue Size
    cout << "Queue Size: " << q.size() << endl;

    return 0;
}