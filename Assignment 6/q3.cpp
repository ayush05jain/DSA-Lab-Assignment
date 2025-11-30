#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

Node* headC = NULL;
DNode* headD = NULL;

void insertC(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    if (headC == NULL) {
        headC = newNode;
        newNode->next = headC;
    } else {
        Node* temp = headC;
        while (temp->next != headC) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = headC;
    }
}
int getSizeC() {
    if (headC == NULL) return 0;
    int count = 0;
    Node* temp = headC;
    do {
        count++;
        temp = temp->next;
    } while (temp != headC);
    return count;
}
void insertD(int val) {
    DNode* newNode = new DNode();
    newNode->data = val;
    newNode->next = NULL;
    if (headD == NULL) {
        newNode->prev = NULL;
        headD = newNode;
    } else {
        DNode* temp = headD;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
int getSizeD() {
    int count = 0;
    DNode* temp = headD;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    int n, val, i;

    cout << "--- Circular Linked List ---\n";
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (i = 0; i < n; i++) {
        cin >> val;
        insertC(val);
    }
    cout << "Size of Circular Linked List: " << getSizeC() << endl;

    cout << "\n--- Doubly Linked List ---\n";

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (i = 0; i < n; i++) {
        cin >> val;
        insertD(val);
    }
    cout << "Size of Doubly Linked List: " << getSizeD() << endl;

    return 0;
}