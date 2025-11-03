#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return searchRecursive(root->left, key);
    }

    return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key) {
            return root;
        }
        else if (key < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return nullptr;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);

    int key = 6;
    Node* foundRec = searchRecursive(root, key);
    Node* foundNonRec = searchNonRecursive(root, key);

    if (foundRec) cout << "Found (Recursive)" << endl; 
    else cout << "Not Found (Recursive)" << endl;

    if (foundNonRec) cout << "Found (Non-Recursive)" << endl; 
    else cout << "Not Found (Non-Recursive)" << endl;

    return 0;
}
