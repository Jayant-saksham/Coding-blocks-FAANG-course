#include<iostream>
using namespace std;
struct node {
    int data;
    struct node *left;
    struct node *right;
};
int search(int in[], int start, int end, int key){
    for(int i=start;i<=end;i++){
        if(in[i]==key){
            return i;
        }
    }
    return -1;
}
struct node *createTreeHelper(int in[], int pre[], int start, int end){
    if(start>end){
        return NULL;
    }
    int i=0;
    int element=pre[i++];
    int inIndex=search(in, start, end, element);
    struct node *root=new node;
    root->data=element;
    if(start==end){
        return root;
    }
    root->left=createTreeHelper(in, pre, start, inIndex-1);
    root->right=createTreeHelper(in, pre, inIndex+1, end);
    return root;
}
struct node *buildTree(int in[], int pre[], int n){
    int index=n-1;
    return createTreeHelper(in, pre, 0, n-1);
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
    int pre[]={1,2,4,3,5,6,7};
    int in[]= {4,2,1,3,6,5,7};
    int n=sizeof(in)/sizeof(in[0]);
    struct node *root = buildTree(in, pre, n);
    inOrder(root);
    return 0;
}