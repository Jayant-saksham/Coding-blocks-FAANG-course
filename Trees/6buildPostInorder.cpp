#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
int index;
struct node *createTree(int in[], int post[], int start, int end){
    if(start>end){
        return NULL;
    }
    int data=post[index];
    index--;
    struct node *root = new node;
    root->data=data;
    int k=-1;
    for(int i=start;i<=end;i++){
        if(data==in[i]){
            k=i;
            break;
        }
    }
    root->right=createTree(in, post, k+1, end);
    root->left=createTree(in, post, start, k-1);
    return root;
}
struct node *buildTree(int in[], int post[], int n){
    index=n-1;
    return createTree(in, post,0, n-1);
}
void inOrder(struct node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main(){
    int post[]={9,3,15,20,7};
    int in[]={9,15,7,20,3};
    int n=sizeof(in)/sizeof(in[0]);
    struct node *root=buildTree(in, post, n);
    return 0;
}