#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
bool isMirror(struct node *left, struct node *right){
    if(right==NULL || left == NULL){
        return right==left;
    }
    if(right->data==right->data){
        return true;
    }
    if(isMirror(left->left, right->right) && isMirror(left->right, right->left)){
        return true;
    }
    return false;    
}
bool isSymetric(struct node *root){
    if(root==NULL){
        return true;
    }
    return isMirror(root->left, root->right);
}
struct node *createTree(){
    cout<<"Enter data : ";
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    struct node *root=new node;
    root->data=x;
    root->left=createTree();
    root->right=createTree();
    return root;
}

int main(){
    struct node *root=createTree();
    cout<<isSymetric(root)<<endl;
    return 0;
}