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
struct node *swapnode(){
    struct node *ptr=head;
    struct node *temp=new node;
    temp->next=NULL;
    while(ptr!=NULL && ptr->next!=NULL){
        temp->next=ptr->next;
        ptr->next=ptr->next->next;
        temp->next->next=ptr;
        ptr=ptr->next;
        temp=temp->next->next;
    }
    return temp->next;
}
int main(){
    int A[]={1,4,5,2,6,3};
    int n=sizeof(A)/sizeof(A[0]);
    create(A, n);
    displayLL();
    swapnode();
    displayLL();
    return 0;
}