#include<iostream>
using namespace std;
struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insert(char val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
bool isPalindrome() {
    if (head == NULL) return true;

    Node* left = head;
    Node* right = head;

    while (right->next != NULL) {
        right = right->next;
    }

    while (left != right && right->next != left) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}
int main() {
    int n;
    char val;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(val);
    }

    if (isPalindrome()) {
        cout << "It is a Palindrome\n";
    } else {
        cout << "It is not a Palindrome\n";
    }

    return 0;
}