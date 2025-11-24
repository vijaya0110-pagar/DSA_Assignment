#include <iostream>
using namespace std;

struct Node {
    int marks;
    string name;
    Node *left, *right;
    Node(int m, string n) { marks=m; name=n; left=right=NULL; }
};

Node* insertNode(Node* root, int m, string n) {
    if(!root) return new Node(m,n);
    if(m > root->marks) root->left = insertNode(root->left,m,n);
    else root->right = insertNode(root->right,m,n);
    return root;
}

void assignRoll(Node* root, int &roll) {
    if(!root) return;
    assignRoll(root->left,roll);
    cout<<roll++<<" "<<root->name<<" "<<root->marks<<endl;
    assignRoll(root->right,roll);
}

int main() {
    int n,m; string name;
    Node *root=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name>>m;
        root=insertNode(root,m,name);
    }
    int roll=1;
    assignRoll(root,roll);
}
