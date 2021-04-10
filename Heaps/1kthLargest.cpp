#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int kthLargest(int A[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<n;i++){
        q.push(A[i]);
        if(q.size()>k){
            q.pop();
        }
    }
    return q.top();        
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<"Enter k : ";
    int k;
    cin>>k;
    cout<<kthLargest(A,n, k)<<endl;
    return 0;
}