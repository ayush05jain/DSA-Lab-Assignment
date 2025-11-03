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

Node* findMin(Node* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }

    return root;
}

Node* successor(Node* root, Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right != nullptr) {
        return findMin(node->right);
    }

    Node* succ = nullptr;

    while (root != nullptr) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } 
        else if (node->data > root->data) {
            root = root->right;
        } 
        else {
            break;
        }
    }

    return succ;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    Node* node = root->left->right;
    Node* succ = successor(root, node);

    if (succ != nullptr) {
        cout << "In-order successor of " << node->data << " is " << succ->data;
    } 
    else {
        cout << "No in-order successor found";
    }

    return 0;
}