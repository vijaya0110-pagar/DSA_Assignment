#include <iostream>
using namespace std;

struct Node {
    int id;
    string name;
    Node *left,*right;
    Node(int i,string n){id=i;name=n;left=right=NULL;}
};

Node* insertNode(Node* root,int id,string name){
    if(!root) return new Node(id,name);
    if(id<root->id) root->left=insertNode(root->left,id,name);
    else root->right=insertNode(root->right,id,name);
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->id<<" "<<root->name<<endl;
    inorder(root->right);
}

bool search(Node* root,int id){
    if(!root) return false;
    if(root->id==id) return true;
    if(id<root->id) return search(root->left,id);
    return search(root->right,id);
}

int main(){
    int n,id; string name;
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>id>>name;
        root=insertNode(root,id,name);
    }
    inorder(root);
    cin>>id;
    cout<<(search(root,id)?"Found":"Not Found");
}
