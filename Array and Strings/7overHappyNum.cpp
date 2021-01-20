#include<iostream>
#include<map>
using namespace std;
int update(int n){
    int sum=0;
    while(n>0){
        int rem=n%10;
        sum+=rem*rem;
        n/=10;
    }
    return sum;
}
bool check(map<int, bool> m, int n){
    if(n==1){
        return true;
    }
    if(m.find(n)!=m.end()){
        return false;
    }
    m.insert(make_pair(n,true));
    n=update(n);
    return check(m, n);
}
bool canConvert(int n){
    map<int,bool>m;
    return check(m,n);  
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<canConvert(n);
    return 0;
}