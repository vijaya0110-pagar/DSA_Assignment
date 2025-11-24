#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}


int countNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int height(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


void mirror(Node* root) {
    if (root == nullptr) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}


void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    
    
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);

    cout << "Total nodes: " << countNodes(root) << "\n";
    cout << "Height of BST: " << height(root) << "\n";

    cout << "Inorder before mirroring: ";
    inorder(root);
    cout << "\n";

    mirror(root);

    cout << "Inorder after mirroring: ";
    inorder(root);
    cout << "\n";

    return 0;
}
