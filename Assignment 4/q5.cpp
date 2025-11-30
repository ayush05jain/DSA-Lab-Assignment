#include<iostream>
#include<queue>
using namespace std;
class StackTwoQueues {
    queue<int> q1, q2;
    public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1.empty()) return;
        q1.pop();
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
class StackOneQueue {
    queue<int> q;
    public:
    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) return;
        q.pop();
    }
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};
int main() {
    int choice, type, val;
    StackTwoQueues s1;
    StackOneQueue s2;

    cout << "1. Stack using Two Queues\n2. Stack using One Queue\nEnter type: ";
    cin >> type;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (type == 1) {
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    s1.push(val);
                    break;
                case 2:
                    if (!s1.empty()) {
                        cout << "Popped: " << s1.top() << endl;
                        s1.pop();
                    } else cout << "Stack Empty\n";
                    break;
                case 3:
                    if (!s1.empty()) cout << "Top: " << s1.top() << endl;
                    else cout << "Stack Empty\n";
                    break;
                case 4: return 0;
            }
        } else {
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    s2.push(val);
                    break;
                case 2:
                    if (!s2.empty()) {
                        cout << "Popped: " << s2.top() << endl;
                        s2.pop();
                    } else cout << "Stack Empty\n";
                    break;
                case 3:
                    if (!s2.empty()) cout << "Top: " << s2.top() << endl;
                    else cout << "Stack Empty\n";
                    break;
                case 4: return 0;
            }
        }
    }
    
    return 0;
}