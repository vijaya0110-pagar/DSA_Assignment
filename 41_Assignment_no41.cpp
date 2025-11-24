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
    if(c < root->code) root->left=insertNode(root->left,c,n,p,q,r,e);
    else root->right=insertNode(root->right,c,n,p,q,r,e);
    return root;
}

Node* findMin(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* deleteCode(Node* root,int c){
    if(!root) return root;
    if(c < root->code) root->left=deleteCode(root->left,c);
    else if(c > root->code) root->right=deleteCode(root->right,c);
    else{
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        Node* t=findMin(root->right);
        root->code=t->code;
        root->right=deleteCode(root->right,t->code);
    }
    return root;
}

Node* deleteExpired(Node* root,string today){
    if(!root) return root;
    root->left=deleteExpired(root->left,today);
    root->right=deleteExpired(root->right,today);
    if(root->exp < today) return deleteCode(root,root->code);
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->code<<" "<<root->name<<endl;
    inorder(root->right);
}

int main(){
    Node* root=NULL;
    int n,c,p,q; string name,r,e,today;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c>>name>>p>>q>>r>>e;
        root=insertNode(root,c,name,p,q,r,e);
    }
    cin>>c;
    root=deleteCode(root,c);
    cin>>today;
    root=deleteExpired(root,today);
    inorder(root);
}
