#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
    struct node *random;
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
void deepCopy(){
    struct node *ptr=head;
    struct node *front=head;
    while(ptr!=NULL){
        front=ptr->next;
        struct node *copy=new node;
        copy->data=ptr->data;
        ptr->next=copy;
        copy->next=front;
        ptr=front;
    }
    ptr=head;
    while(ptr!=NULL){
        if(ptr->random!=NULL){
            ptr->next->random=ptr->random->next;
        }
        ptr=ptr->next->next;
    }
    ptr=head;
    struct node *pseudoHead = new node;
    pseudoHead->data=0;
    struct node *copy = pseudoHead;
    while(ptr!=NULL){
        front=ptr->next->next;
        copy->next=ptr->next;
        ptr->next=front;
        copy=copy->next;
        ptr=front;
    }
}
int main(){
    int A[]={1,4,5,2,6,3};
    int n=sizeof(A)/sizeof(A[0]);
    return 0;
}