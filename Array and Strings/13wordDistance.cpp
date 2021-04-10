#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    string a;
    string b;
    cin>>a>>b;
    int ans=INT8_MAX;
    int w1=-1, w2=-1;
    for(int i=0;i<n;i++){
        if(s[i]==a){
            w1=i;
        }
        if(s[i]==b){
            w2=i;
        }
        if(w1!=-1 && w2!=-1){
            ans=min(ans, abs(w2-w1));
        }
    }
    return 0;
}