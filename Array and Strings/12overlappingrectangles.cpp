#include<iostream>
using namespace std;
bool isOverlap(int R1[], int R2[]){
    if(R1[2]<R2[0] || R1[1]>=R2[3] || R1[0]>=R2[2] || R1[3]<=R2[1]){
        return false;
    }
    return true;
}
int main(){
    int R1[4];
    for(int i=0;i<4;i++){
        cin>>R1[i];
    }
    int R2[4];
    for(int i=0;i<4;i++){
        cin>>R2[i];
    }
    cout<<isOverlap(R1, R2)<<endl;
    return 0;
}