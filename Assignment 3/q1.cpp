#include<iostream>
using namespace std;

int stack[100], n, top = -1;
bool isFull() {
    if (top >= n - 1)
        return true;
    else
        return false;
}
bool isEmpty() {
    if (top == -1)
        return true;
    else
        return false;
}
void push(int val) {
    if (isFull()) {
        cout << "Stack Overflow\n";
    } else {
        top++;
        stack[top] = val;
        cout << "Pushed successfully.\n";
    }
}
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
    } else {
        cout << "Popped element: " << stack[top] << endl;
        top--;
    }
}
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Top element: " << stack[top] << endl;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    int choice, val;
    cout << "Enter size of stack: ";
    cin >> n;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. IsEmpty\n4. IsFull\n5. Peek\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty()) cout << "Stack is Empty\n";
                else cout << "Stack is not Empty\n";
                break;
            case 4:
                if (isFull()) cout << "Stack is Full\n";
                else cout << "Stack is not Full\n";
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