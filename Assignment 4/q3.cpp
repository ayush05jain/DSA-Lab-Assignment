#include<iostream>
#include<queue>
using namespace std;
void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even for interleaving." << endl;
        return;
    }

    int half = n / 2;
    int stack[100]; 
    int top = -1;

    for (int i = 0; i < half; i++) {
        stack[++top] = q.front();
        q.pop();
    }

    while (top != -1) {
        q.push(stack[top--]);
    }

    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < half; i++) {
        stack[++top] = q.front();
        q.pop();
    }
    
    while (top != -1) {
        q.push(stack[top--]);  
        q.push(q.front());   
        q.pop();
    }
}
int main() {
    queue<int> q;
    int n, val;

    cout << "Enter number of elements (even number): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}