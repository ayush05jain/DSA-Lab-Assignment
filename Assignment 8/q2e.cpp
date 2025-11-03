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
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* findMax(Node* root) {
    while (root != nullptr && root->right != nullptr) {
        root = root->right;
    }

    return root;
}

Node* predecessor(Node* root, Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->left != nullptr) {
        return findMax(node->left);
    }

    Node* pred = nullptr;

    while (root != nullptr) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } 
        else if (node->data < root->data) {
            root = root->left;
        } 
        else {
            break;
        }
    }

    return pred;
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
    Node* pred = predecessor(root, node);

    if (pred != nullptr) {
        cout << "In-order predecessor of " << node->data << " is " << pred->data;
    } 
    else {
        cout << "No in-order predecessor found";
    }

    return 0;
}