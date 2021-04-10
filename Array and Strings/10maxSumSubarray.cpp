#include<iostream>
using namespace std;
int main(){
    int max=INT8_MIN;
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int currentSum=0;
    for(int i=0;i<n;i++){
        currentSum +=A[i];
        if(currentSum>max){
            max=currentSum;
        }
        if(currentSum<0){
            currentSum=0;
        }
    }
    cout<<max<<endl;
    return 0;
}