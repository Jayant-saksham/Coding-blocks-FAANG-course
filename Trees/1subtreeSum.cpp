#include<bits/stdc++.h>
using namespace std;
char A[1000];
vector<int>v;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
void StringtoInt(){
    char *ans=strtok(A," ");
    while(ans!=NULL){
        v.push_back(stoi(ans));
        ans=strtok(NULL, " ");
    }
}
struct node *createTree(){
    if(v.empty() || strlen(A) == 0){
        return NULL;
    }
    int digit=v[0];
    struct node *root=new node;
    root->data=digit;
    queue<struct node*> q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<v.size()){
        struct node *ptr=q.front();
        q.pop();
        digit=v[i++];
        ptr->left = new node;
        ptr->left->data=digit;
        q.push(ptr->left);
        if(i>=v.size()){
            break;
        }
        digit=v[i++];
        ptr->right=new node;
        ptr->right->data=digit;
        q.push(ptr->right);
        if(i>=v.size()){
            break;
        }
    }
    return root;
}
void preOrder(struct node *root){
    if(root){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int Sum(struct node *root){
    if(root==NULL){
        return 0;
    }
    int leftSum=Sum(root->left);
    int rightSum=Sum(root->right);
    return root->data+leftSum+rightSum;
}
int countSubTrees(struct node *root, int sum){
    int ans=0;
    if(root==NULL){
        return 0;
    }
    if(Sum(root)==sum){
        ans=1;
    }
    int left_Subtrees = countSubTrees(root->left, sum);
    int right_Subtrees = countSubTrees(root->right, sum);
    return ans+left_Subtrees+right_Subtrees;

}
int main(){
    cin.getline(A, 1000);
    StringtoInt();
    struct node *root=createTree();
    preOrder(root);
    // int sum;
    // cin>>sum;
    // cout<<countSubTrees(root, sum)<<endl;

    return 0;
}