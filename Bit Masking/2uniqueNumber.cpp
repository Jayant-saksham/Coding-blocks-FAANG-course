#include<iostream>
using namespace std;
void findUnique(int A[], int n){
    int XOR=A[0];
    for(int i=1;i<n;i++){
        XOR^=A[i];
    }
    int i=0;
    int temp=XOR;
    while(temp>0){
        if(temp&1){
            break;
        }
        i++;
        temp = temp>>1;
    }
    int mask = (1<<i);
    int firstNum= 0;
    for(int i=0;i<n;i++){
        if(mask&A[i]){
            firstNum^=A[i];
        }
    }
    int secondNum = XOR^firstNum;
    cout<<"First number "<<firstNum<<endl;
    cout<<"Second number "<<secondNum<<endl;
}
int main(){
    int A[]={1,3,5,6,3,2,1,2};
    int n=sizeof(A)/sizeof(A[0]);
    findUnique(A,n);
    return 0;
}