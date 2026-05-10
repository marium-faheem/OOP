#include <iostream>
#include <string>
using namespace std;

// Queue Class
class Queue {

private:
    string* arr;
    int front;
    int rear;
    int count;
    int capacity;

public:

    // Constructor
    Queue(int size = 5) {
        capacity = size;
        arr = new string[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Check if Queue is Empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if Queue is Full
    bool isFull() {
        return count == capacity;
    }

    // Resize Queue
    void resize() {

        int newCapacity = capacity * 2;

        string* temp = new string[newCapacity];

        // Copy old elements
        for (int i = 0; i < count; i++) {
            temp[i] = arr[(front + i) % capacity];
        }

        delete[] arr;

        arr = temp;

        front = 0;
        rear = count - 1;

        capacity = newCapacity;

        cout << "Queue Resized to "
             << capacity << endl;
    }

    // Enqueue Function
    void enqueue(string job) {

        if (isFull()) {
            resize();
        }

        rear = (rear + 1) % capacity;

        arr[rear] = job;

        count++;

        cout << job
             << " added to print queue." << endl;
    }

    // Dequeue Function
    string dequeue() {

        if (isEmpty()) {
            return "";
        }

        string job = arr[front];

        front = (front + 1) % capacity;

        count--;

        return job;
    }

    // Display Queue
    void displayQueue() {

        if (isEmpty()) {
            cout << "Print Queue is Empty!" << endl;
            return;
        }

        cout << "\nCurrent Print Queue: ";

        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity]
                 << " ";
        }

        cout << endl;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }
};

int main() {

    // Create Print Queue
    Queue printerQueue(3);

    // Print Jobs Arrive
    printerQueue.enqueue("Job 1");
    printerQueue.enqueue("Job 2");
    printerQueue.enqueue("Job 3");

    printerQueue.displayQueue();

    // Queue Full -> Resize
    printerQueue.enqueue("Job 4");

    printerQueue.displayQueue();

    cout << "\n--- Printing Started ---\n" << endl;

    // Process Jobs using FIFO
    while (!printerQueue.isEmpty()) {

        string currentJob =
            printerQueue.dequeue();

        cout << "Printing "
             << currentJob << "..." << endl;

        cout << currentJob
             << " completed.\n" << endl;
    }

    cout << "No more jobs in queue." << endl;
    cout << "Printer is now idle." << endl;

    return 0;
}