#include<iostream>
#include<set>
using namespace std;
int min(int a, int b){
    return a>b?a:b;
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    int ans = min(n/2,s.size());
    cout<<ans<<endl;

    return 0;
}