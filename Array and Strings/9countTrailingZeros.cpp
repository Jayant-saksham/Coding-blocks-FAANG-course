#include<iostream>
using namespace std;
int countZeros(int n){
    int count=0;
    int p=5;
    while(n/p>0){
        count+=(n/p);
        p*=5;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<countZeros(n)<<endl;
    return 0;
}