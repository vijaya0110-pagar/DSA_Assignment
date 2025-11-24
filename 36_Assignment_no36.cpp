#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};


Node* createNode(int value) {
    return new Node(value);
}


void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


int countLeafNodes(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}


void mirrorImage(Node* root) {
    if (root == nullptr) return;

    
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

   
    mirrorImage(root->left);
    mirrorImage(root->right);
}


int main() {
    
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << "\n";

    int leafCount = countLeafNodes(root);
    cout << "Number of leaf nodes: " << leafCount << "\n";

    mirrorImage(root);

    cout << "Inorder Traversal of Mirror Image: ";
    inorderTraversal(root);
    cout << "\n";

    cout << "Preorder Traversal of Mirror Image: ";
    preorderTraversal(root);
    cout << "\n";

    return 0;
}
