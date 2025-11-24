#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node(int d){data=d;left=right=NULL;}
};

Node* insertNode(Node* root,int d){
    if(!root) return new Node(d);
    if(d<root->data) root->left=insertNode(root->left,d);
    else root->right=insertNode(root->right,d);
    return root;
}

Node* findMin(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* deleteNode(Node* root,int d){
    if(!root) return root;
    if(d<root->data) root->left=deleteNode(root->left,d);
    else if(d>root->data) root->right=deleteNode(root->right,d);
    else{
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        Node* t=findMin(root->right);
        root->data=t->data;
        root->right=deleteNode(root->right,t->data);
    }
    return root;
}

bool searchNode(Node* root,int d){
    if(!root) return false;
    if(root->data==d) return true;
    if(d<root->data) return searchNode(root->left,d);
    return searchNode(root->right,d);
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root=NULL; int ch,x;
    while(cin>>ch){
        if(ch==1){cin>>x; root=insertNode(root,x);}
        else if(ch==2){cin>>x; root=deleteNode(root,x);}
        else if(ch==3){cin>>x; cout<<(searchNode(root,x)?"Found":"Not Found")<<endl;}
        else if(ch==4){inorder(root); cout<<endl;}
        else break;
    }
}
