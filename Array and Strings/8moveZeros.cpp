#include<iostream>
using namespace std;
void approachh1(int A[], int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            count++;
        }
        else{
            cout<<A[i]<<" ";
        }
    }
    for(int i=0;i<count;i++){
        cout<<0<<" ";
    }
}
void approach2(int A[], int n){
    int j=0,i=0;
    for(;i<n;i++){
        if(A[i]!=0){
            swap(A[i], A[j]);
            j++;
        }
    }
    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    approach2(A,n);
    return 0;
}