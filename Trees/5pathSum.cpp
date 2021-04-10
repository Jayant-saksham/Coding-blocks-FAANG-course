#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
bool hasPathSum(struct node *root, int sum, int currentSum){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL && root->right==NULL){
        if(currentSum+root->data==sum){
            return true;
        }
        else{
            return false;
        }
    }
    return (hasPathSum(root->left, currentSum+root->data, currentSum) || hasPathSum(root->right, currentSum+root->data, currentSum));    
}
struct node *createTree(){

}
int main(){
    struct node *root=createTree();
    return 0;
}