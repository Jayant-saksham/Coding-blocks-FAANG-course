#include<iostream>
#include<stack>
using namespace std;
void uniqueString(string s){
    stack<char> st;
    bool A[26]={false};
    int lastIndex[26]={0};
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        lastIndex[s[i]-'a']=i;
    }
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(!A[ch]){
            while(ch<st.top() && !st.empty() && lastIndex[st.top() -'a']>i){
                A[st.top()-'a']=false;
                st.pop();
            }
            st.push(ch);
            A[ch-'a']=true;
        }
    }
    int n=st.size();
    A[n--]='\0';
    char *ans = new char[n+1];
    while(!s.empty()){
        A[n]=st.top();
        st.pop();
        n--;
    }
    cout<<ans<<endl;
}
int main(){
    string s;
    cin>>s;
    uniqueString(s);
    return 0;
}