#include <iostream>
using namespace std;

struct Node {
    int code,price,qty;
    string name,recv,exp;
    Node *left,*right;
    Node(int c,string n,int p,int q,string r,string e){
        code=c; name=n; price=p; qty=q; recv=r; exp=e;
        left=right=NULL;
    }
};

Node* insertNode(Node* root,int c,string n,int p,int q,string r,string e){
    if(!root) return new Node(c,n,p,q,r,e);
    if(n < root->name) root->left=insertNode(root->left,c,n,p,q,r,e);
    else root->right=insertNode(root->right,c,n,p,q,r,e);
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->name<<" "<<root->code<<" "<<root->qty<<endl;
    inorder(root->right);
}

void expired(Node* root,string today){
    if(!root) return;
    cout<<root->name<<" "<<root->exp<<endl;
    expired(root->left,today);
    expired(root->right,today);
}

int main(){
    Node* root=NULL;
    int n,c,p,q; string name,r,e,today;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c>>name>>p>>q>>r>>e;
        root=insertNode(root,c,name,p,q,r,e);
    }
    inorder(root);
    cin>>today;
    expired(root,today);
}
