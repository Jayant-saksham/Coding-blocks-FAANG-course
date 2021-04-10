#include<iostream>
using namespace std;
int missingNumber(int A[], int n){
    int XOR=A[0];
    for(int i=1;i<n;i++){
        XOR^=A[i];
    }
    return XOR;
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<missingNumber(A,n)<<endl;
    return 0;
}