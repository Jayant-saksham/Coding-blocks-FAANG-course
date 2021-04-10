#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *last=NULL;
void create(int A[], int n){
    struct node *first=new node;
    first->data=A[0];
    first->next=NULL;
    head=first;
    last=head;
    for(int i=1;i<n;i++){
        struct node *temp = new node;
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }    
}
void displayLL(){
    struct node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
void removeKthElement(int k){
    if(head==NULL){
        return;
    }
    struct node *slow=head;
    struct node *fast=head;
    for(int i=0;i<k;i++){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    displayLL();
}
int main(){
    int A[]={1,4,5,2,6,3};
    int n=sizeof(A)/sizeof(A[0]);
    create(A, n);
    displayLL();
    cout<<"Enter kth element from last : ";
    int k;
    cin>>k;
    removeKthElement(k);
    return 0;
}