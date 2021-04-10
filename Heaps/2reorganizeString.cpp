#include<bits/stdc++.h>
using namespace std;
string reorgranize(string s){
    priority_queue<pair<int,char>>q;
    string ans="";
    int fre[26]={0};
    for(int i=0;i<s.size();i++){
        fre[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(fre[i]>0){
            q.push(make_pair(fre[i], 'a'+i));
        }
    }
    while(!q.empty()){
        if(q.size()>=2){
            pair<int, char> p1;
            pair<int,char>p2;
            p1=q.top();
            q.pop();
            p2=q.top();
            q.pop();
            ans+=p1.second;
            ans+=p2.second;
            p1.first--;
            p2.first--;
            if(p1.first>0){
                q.push(p1);
            }
            if(p2.first>0){
                q.push(p2);
            }
        }
        else if(q.size()==1){
            if(q.top().first>1){
                return "";
            }
            else{
                ans+=q.top().second;
                q.pop();
            }
        }
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<reorgranize(s)<<endl;
    return 0;
}