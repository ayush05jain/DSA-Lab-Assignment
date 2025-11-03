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

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr) {
        return true;
    }
    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }

    bool leftOk = isBSTUtil(root->left, minVal, root->data);
    bool rightOk = isBSTUtil(root->right, root->data, maxVal);

    if (leftOk && rightOk) {
        return true;
    } 
    else {
        return false;
    }
}

bool isBST(Node* root) {
    return isBSTUtil(root, -1000000, 1000000);
}

int main() {
    Node* root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    if (isBST(root)) {
        cout << "The tree is a BST";
    } 
    else {
        cout << "The tree is not a BST";
    }

    return 0;
}