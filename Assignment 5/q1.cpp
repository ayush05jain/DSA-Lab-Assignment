#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBegin(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << val << " at beginning.\n";
}
void insertEnd(int val) {
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
    cout << "Inserted " << val << " at end.\n";
}
void insertAfter(int val, int target) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Target node " << target << " not found.\n";
    } else {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " after " << target << ".\n";
    }
}
void insertBefore(int val, int target) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == target) {
        insertBegin(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Target node " << target << " not found.\n";
    } else {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " before " << target << ".\n";
    }
}
void deleteBegin() {
    if (head == NULL) {
        cout << "List is empty.\n";
    } else {
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }
}
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
    } else if (head->next == NULL) {
        cout << "Deleted " << head->data << " from end.\n";
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        cout << "Deleted " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = NULL;
    }
}
void deleteSpecific(int target) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == target) {
        deleteBegin();
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Node " << target << " not found.\n";
    } else {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        cout << "Deleted node " << target << ".\n";
        delete toDelete;
    }
}
void search(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Node found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found.\n";
}
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
    } else {
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}
int main() {
    int choice, val, target;
    while (true) {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Before Node\n4. Insert After Node\n";
        cout << "5. Delete Beginning\n6. Delete End\n7. Delete Specific Node\n8. Search\n9. Display\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBegin(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                insertBefore(val, target);
                break;
            case 4:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                insertAfter(val, target);
                break;
            case 5:
                deleteBegin();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> target;
                deleteSpecific(target);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                search(val);
                break;
            case 9:
                display();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
    
    return 0;
}