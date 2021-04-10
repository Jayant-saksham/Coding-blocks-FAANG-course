#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    struct node *root=new node;
    root->data=data;
    root->left=createTree();
    root->right=createTree();
    return root;
}

struct node *findNode(struct node *root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    struct node *left=findNode(root->left, key);
    struct node *right=findNode(root->right, key);
    return left==NULL?right:left;
}
int countNodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    int left_nodes_count = countNodes(root->left);
    int right_nodes_count = countNodes(root->right);
    return 1+left_nodes_count+right_nodes_count;

}
bool BigBang(struct node *root, int choice, int nodes){
    struct node *ptr=findNode(root,choice);
    int left=countNodes(root->left);
    int right=countNodes(root->right);
    int remaining_nodes = nodes-(left+right)-1;
    if(left>right+remaining_nodes){
        return true;
    }
    if(right>left+remaining_nodes){
        return true;
    }
    if(remaining_nodes>left+right){
        return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int nodes;
    cin>>nodes;
    int choice;
    cin>>choice;
    struct node *root=createTree();
    cout<<BigBang(root, choice, nodes)<<endl;
    return 0;
}