#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void display() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data << endl;
}
int main() {
    int n, val;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    
    if (n > 0) {
        cout << "Enter values: ";
        for(int i = 0; i < n; i++) {
            cin >> val;
            insert(val);
        }
        
        cout << "Output: ";
        display();
    }
    
    return 0;
}