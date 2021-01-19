#include<iostream>
#include<vector>
using namespace std;
int Fun(vector<string>v, int i,string s){
    if(i==v.size()){
        int freq[26]={0};
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a'] ==1){
                return 0;
            }
            else{
                freq[s[i]-'a']++;
            }
        }
        return s.length();
    }
    int opt1,opt2;
    opt1=opt2=INT16_MIN;
    if(s.length() +v[i].length()<=26){
        opt1=Fun(v,i+1,s+v[i]);
    }
    opt2=Fun(v,i+1,s);
    return max(opt1, opt2);

}
int UniqueString(vector<string>v){
    string s="";
    return Fun(v,0,s);
}
int main(){
    vector<string> v;
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    cout<<UniqueString(v)<<endl;
    return 0;
}