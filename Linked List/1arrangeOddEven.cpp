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
void approach1(){
    struct node *ptr=head;
    int count=0;
    while(ptr->next!=NULL){
        count++;
        ptr=ptr->next;
    }
    count=count&1?(count/2)+1:count/2;
    ptr=head;
    while(count--){
        last->next=ptr->next;
        ptr->next=ptr->next->next;
        last->next->next=NULL;
        ptr=ptr->next;
        last=last->next;
    }
}
void approach2(){
    if(head==NULL){
        return;
    }
    struct node *odd=head;
    struct node *oh=head;
    struct node *even=head->next;
    struct node *eh=head->next;
    while(even && even->next){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=eh;
}
void displayNewLL(){
    struct node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main(){
    int A[]={1,4,7,8,5,2,3,6,9};
    int n=sizeof(A)/sizeof(A[0]);
    create(A,n);
    displayLL();
    approach2();
    displayNewLL();
    return 0;
}