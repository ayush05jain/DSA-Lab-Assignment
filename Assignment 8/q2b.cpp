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
    else if (data < root->data) {
        root->left = insert(root->left, data);
    } 
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* findMax(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    while (root->right != nullptr) {
        root = root->right;
    }

    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);

    Node* maxNode = findMax(root);

    if (maxNode) {
        cout << "Maximum element: " << maxNode->data;
    } 
    else {
        cout << "Tree is empty";
    }

    return 0;
}