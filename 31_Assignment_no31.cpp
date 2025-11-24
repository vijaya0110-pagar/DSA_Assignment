#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);  
    }
    if (val < root->data) {
        root->left = insert(root->left, val);  
    } else {
        root->right = insert(root->right, val); 
    }
    return root;
}


void levelDisplay(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;  
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
    cout << endl;
}

int main() {
    Node* root = NULL;      
    
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);

    cout << "Tree (level-wise): ";
    levelDisplay(root);

    return 0;
}
