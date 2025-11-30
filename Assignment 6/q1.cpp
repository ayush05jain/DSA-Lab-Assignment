#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* headC = NULL;

void insertBeginC(int val) {
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
        newNode->next = headC;
        temp->next = newNode;
        headC = newNode;
    }
}
void insertEndC(int val) {
    if (headC == NULL) {
        insertBeginC(val);
        return;
    }
    Node* newNode = new Node();
    newNode->data = val;
    Node* temp = headC;
    while (temp->next != headC) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = headC;
}
void insertAfterC(int val, int target) {
    if (headC == NULL) return;
    Node* temp = headC;
    do {
        if (temp->data == target) {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != headC);
    cout << "Target not found.\n";
}
void insertBeforeC(int val, int target) {
    if (headC == NULL) return;
    if (headC->data == target) {
        insertBeginC(val);
        return;
    }
    Node* temp = headC;
    Node* prev = NULL;
    do {
        if (temp->data == target) {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = temp;
            prev->next = newNode;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != headC);
    cout << "Target not found.\n";
}
void deleteNodeC(int key) {
    if (headC == NULL) return;

    if (headC->data == key && headC->next == headC) {
        delete headC;
        headC = NULL;
        return;
    }

    if (headC->data == key) {
        Node* temp = headC;
        while (temp->next != headC) {
            temp = temp->next;
        }
        temp->next = headC->next;
        Node* toDelete = headC;
        headC = headC->next;
        delete toDelete;
        return;
    }

    Node* temp = headC;
    Node* prev = NULL;
    do {
        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != headC);
    cout << "Node not found.\n";
}
void searchC(int key) {
    if (headC == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = headC;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != headC);
    cout << "Not found.\n";
}
void displayC() {
    if (headC == NULL) {
        cout << "Empty\n";
        return;
    }
    Node* temp = headC;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != headC);
    cout << "(Head)\n";
}
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* headD = NULL;

void insertBeginD(int val) {
    DNode* newNode = new DNode();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = headD;
    if (headD != NULL) {
        headD->prev = newNode;
    }
    headD = newNode;
}
void insertEndD(int val) {
    if (headD == NULL) {
        insertBeginD(val);
        return;
    }
    DNode* newNode = new DNode();
    newNode->data = val;
    newNode->next = NULL;
    DNode* temp = headD;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertAfterD(int val, int target) {
    DNode* temp = headD;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Target not found.\n";
        return;
    }
    DNode* newNode = new DNode();
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
void insertBeforeD(int val, int target) {
    if (headD == NULL) return;
    if (headD->data == target) {
        insertBeginD(val);
        return;
    }
    DNode* temp = headD;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Target not found.\n";
        return;
    }
    DNode* newNode = new DNode();
    newNode->data = val;
    newNode->prev = temp->prev;
    newNode->next = temp;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
}
void deleteNodeD(int key) {
    if (headD == NULL) return;
    
    if (headD->data == key) {
        DNode* toDelete = headD;
        headD = headD->next;
        if (headD != NULL) {
            headD->prev = NULL;
        }
        delete toDelete;
        return;
    }

    DNode* temp = headD;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found.\n";
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    delete temp;
}
void searchD(int key) {
    DNode* temp = headD;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found.\n";
}
void displayD() {
    DNode* temp = headD;
    cout << "NULL <- ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}
void circularMenu() {
    int choice, val, target;
    while (true) {
        cout << "\n--- Circular Linked List ---\n";
        cout << "1. Insert Begin\n2. Insert End\n3. Insert After\n4. Insert Before\n";
        cout << "5. Delete Node\n6. Search\n7. Display\n8. Back\nChoice: ";
        cin >> choice;
        if (choice == 8) break;
        switch (choice) {
            case 1: cout << "Val: "; cin >> val; insertBeginC(val); break;
            case 2: cout << "Val: "; cin >> val; insertEndC(val); break;
            case 3: cout << "Target: "; cin >> target; cout << "Val: "; cin >> val; insertAfterC(val, target); break;
            case 4: cout << "Target: "; cin >> target; cout << "Val: "; cin >> val; insertBeforeC(val, target); break;
            case 5: cout << "Key to delete: "; cin >> target; deleteNodeC(target); break;
            case 6: cout << "Key to search: "; cin >> target; searchC(target); break;
            case 7: displayC(); break;
        }
    }
}
void doublyMenu() {
    int choice, val, target;
    while (true) {
        cout << "\n--- Doubly Linked List ---\n";
        cout << "1. Insert Begin\n2. Insert End\n3. Insert After\n4. Insert Before\n";
        cout << "5. Delete Node\n6. Search\n7. Display\n8. Back\nChoice: ";
        cin >> choice;
        if (choice == 8) break;
        switch (choice) {
            case 1: cout << "Val: "; cin >> val; insertBeginD(val); break;
            case 2: cout << "Val: "; cin >> val; insertEndD(val); break;
            case 3: cout << "Target: "; cin >> target; cout << "Val: "; cin >> val; insertAfterD(val, target); break;
            case 4: cout << "Target: "; cin >> target; cout << "Val: "; cin >> val; insertBeforeD(val, target); break;
            case 5: cout << "Key to delete: "; cin >> target; deleteNodeD(target); break;
            case 6: cout << "Key to search: "; cin >> target; searchD(target); break;
            case 7: displayD(); break;
        }
    }
}
int main() {
    int choice;
    while (true) {
        cout << "\nMAIN MENU\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) circularMenu();
        else if (choice == 2) doublyMenu();
        else if (choice == 3) break;
        else cout << "Invalid\n";
    }
    return 0;
}