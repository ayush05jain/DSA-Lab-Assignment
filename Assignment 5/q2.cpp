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
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}
void countAndDelete(int key) {
    int count = 0;
    Node* toDelete;

    while (head != NULL && head->data == key) {
        toDelete = head;
        head = head->next;
        delete toDelete;
        count++;
    }

    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            count++;
        } else {
            temp = temp->next;
        }
    }
    cout << "Count: " << count << endl;
}
int main() {
    int n, val, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(val);
    }

    cout << "Enter key to count and delete: ";
    cin >> key;

    cout << "Original List: ";
    display();

    countAndDelete(key);

    cout << "Updated Linked List: ";
    display();

    return 0;
}