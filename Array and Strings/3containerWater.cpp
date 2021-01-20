#include<iostream>
using namespace std;
int maxWater(int A[], int left, int right){
    int area = 0;
    while(left<right){
        area = max(area, min(A[left], A[right])*(right-left));
        if(A[left]<A[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return area;
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<maxWater(A,0,n-1)<<endl;
    return 0;
}