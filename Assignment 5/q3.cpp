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
void findMiddle() {
    Node* slow = head;
    Node* fast = head;

    if (head != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }
}
int main() {
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(val);
    }
    findMiddle();

    return 0;
}