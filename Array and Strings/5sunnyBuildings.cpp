#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int maxHeight = 0;
    int count = 0;
    vector<int>v;
    for(int i=0;i<n;i++){
        if(A[i]>=maxHeight){
            count++;
            maxHeight=max(maxHeight, A[i]);
            v.push_back(A[i]);
        }
    }
    cout<<"count : "<<count<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    return 0;
}