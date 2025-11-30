#include<iostream>
using namespace std;

int cQueue[100], n, front = -1, rear = -1;

bool isFull() {
    if ((rear + 1) % n == front)
        return true;
    else
        return false;
}
bool isEmpty() {
    if (front == -1)
        return true;
    else
        return false;
}
void enqueue(int val) {
    if (isFull()) {
        cout << "Queue Overflow\n";
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % n;
        cQueue[rear] = val;
        cout << "Inserted successfully.\n";
    }
}
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
    } else {
        cout << "Deleted element: " << cQueue[front] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % n;
        }
    }
}
void peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Front element: " << cQueue[front] << endl;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << cQueue[i] << " ";
            i = (i + 1) % n;
        }
        cout << cQueue[rear] << endl;
    }
}
int main() {
    int choice, val;
    cout << "Enter size of queue: ";
    cin >> n;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Peek\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if (isEmpty()) cout << "Queue is Empty\n";
                else cout << "Queue is not Empty\n";
                break;
            case 4:
                if (isFull()) cout << "Queue is Full\n";
                else cout << "Queue is not Full\n";
                break;
            case 5:
                peek();
                break;
            case 6:
                display();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}