#include <iostream>
#include <stack>
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


Node* createSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}


void inorderNonrecursive(Node* root) {
    stack<Node*> s;
    Node* current = root;
    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}


void preorderNonrecursive(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";
        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
    cout << endl;
}


int countLeafNodes(Node* root) {
    if (root == nullptr) return 0;
    stack<Node*> s;
    s.push(root);
    int leafCount = 0;
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        if (current->left == nullptr && current->right == nullptr)
            leafCount++;
        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
    return leafCount;
}


void mirrorImage(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
       
        Node* temp = current->left;
        current->left = current->right;
        current->right = temp;
        if (current->left) s.push(current->left);
        if (current->right) s.push(current->right);
    }
}

int main() {
    Node* root = createSampleTree();

    cout << "Inorder Traversal (Nonrecursive): ";
    inorderNonrecursive(root);

    cout << "Preorder Traversal (Nonrecursive): ";
    preorderNonrecursive(root);

    cout << "Number of leaf nodes: " << countLeafNodes(root) << endl;

    mirrorImage(root);
    cout << "Inorder Traversal After Mirroring: ";
    inorderNonrecursive(root);

    return 0;
}

/*
#include <iostream>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to create a new node
Node* createNode(int value) {
    return new Node(value);
}

// Recursive function for inorder traversal
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Recursive function for preorder traversal
void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Recursive function to count the number of leaf nodes
int countLeafNodes(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Recursive function to convert tree into its mirror image
void mirrorImage(Node* root) {
    if (root == nullptr) return;

    // Swap left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively call on children
    mirrorImage(root->left);
    mirrorImage(root->right);
}

// Main function to demonstrate the operations
int main() {
    
    Creating the following binary tree:
           1
          / \
         2   3
        / \   \
       4   5   6
    
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
*/