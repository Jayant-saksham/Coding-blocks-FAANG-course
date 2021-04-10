#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    if(n&1){
        int i=-(n/2);
        while(i!=(n/2)){
            v.push_back(i);
            i+=1;
        }   
    }
    else{
        int i=-(n/2);
        while(i!=(n/2)){
            if(i==0){
                i+=1;
                continue;
            }
            v.push_back(i);
            i+=1;
        }
    }
    v.push_back(n/2);
    for(auto i : v){
        cout<<i<<" ";
    }
    return 0;
}