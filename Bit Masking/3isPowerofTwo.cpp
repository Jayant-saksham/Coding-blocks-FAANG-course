#include<iostream>
using namespace std;
bool isPowerOfTwo(int n){
    return n && (!(n&(n-1)));
}
bool isPowerofTwo2(int n){
    if(n<0){
        return false;
    }
    int count=0;
    while(n){
        if(n&1){
            count++;
        }
       n = n>>1;
    }
    if(count==1){
        return true;
    }
    else{
        return false; 
    }
}
int main(){
    int n;
    cin>>n;
    cout<<isPowerOfTwo(n)<<endl;
    return 0;
}