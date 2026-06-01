class Queue {
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    ~Queue() { delete[] arr; }

    bool isEmpty() { return size == 0; }
    bool isFull()  { return size == capacity; }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear++;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front++;
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];  // front wala element!
    }
};

int main(){
    Queue q(3);
    q.enqueue(22);
    q.enqueue(21);
    q.enqueue(20);
    cout<<"Peeking: "<<q.peek()<<endl;
    q.enqueue(19);
    cout<<"Full? "<<q.isFull()<<endl;
}