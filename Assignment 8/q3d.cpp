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

int minDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    else if (root->left == nullptr) {
        return minDepth(root->right) + 1;
    }
    else if (root->right == nullptr) {
        return minDepth(root->left) + 1;
    }

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (leftDepth < rightDepth) {
        return leftDepth + 1;
    } 
    else {
        return rightDepth + 1;
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    cout << "Minimum depth of BST: " << minDepth(root);

    return 0;
}