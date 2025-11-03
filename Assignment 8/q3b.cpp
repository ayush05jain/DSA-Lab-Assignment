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
    else {
        cout << "Duplicate not allowed: " << data << endl;
    }

    return root;
}

Node* findMin(Node* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    } 
    else if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } 
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } 
        else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        } 
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);

    cout << root->data << " ";

    inOrder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);

    cout << "In-order before deletion: ";

    inOrder(root);
    cout << endl;

    root = deleteNode(root, 3);

    cout << "In-order after deletion: ";
    inOrder(root);

    return 0;
}