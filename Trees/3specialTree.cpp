#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createSpeicalTree(int *A,int low, int high){
    if(low>high){
        return NULL;
    }
    int k=low;
    for(int i=low;i<=high;i++){
        if(A[i]>A[k]){
            k = i;
        }
    }
    struct node *root=new node;
    root->data=A[k];
    root->left=createSpeicalTree(A, low, k-1);
    root->right=createSpeicalTree(A, k+1, high);
    return root;
}
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    struct node *root = createSpeicalTree(A, 0, n-1);
    inorder(root);
    return 0;
}