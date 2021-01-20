#include<iostream>
#include<vector>
using namespace std;
int next(vector<int> v, int i){
    return (i+v[i]+v.size())%v.size();
}
bool isCycle(vector<int> v){
    int n=v.size();
    for(int i=0;i<n;i++){
        int slow=i;
        int fast=i;
        while(v[slow]*v[next(v,slow)]>0 &&  
        v[fast]*v[next(v,fast)]>0 && 
        v[fast]*v[next(v,next(v,fast))]){
            slow=next(v,slow);
            fast=next(v,next(v,fast));
            if(slow==fast){
                if(slow==next(v,slow)){
                    break;
                }
                return true;
            }
        }
    }
}

int main(){
    vector<int> v;
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<isCycle(v)<<endl;
    return 0;
}