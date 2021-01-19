// Find all elements which appear more than n/3
#include<iostream>
#include<vector>
using namespace std;
vector<int> majorityElements(vector<int> V){
    vector<int> output;
    int element1=V[0];
    int count1=1;
    int element2=0;
    int count2=0;
    for(int i=0;i<V.size();i++){
        if(V.at(i)==element1){
            count1++;
        }
        else if(V.at(i)==element2){
            count2++;
        }
        else if(count1==0){
            element1=V.at(i);
            count1=1;
        }
        else if(count2==0){
            element2=V.at(i);
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1=0;
    count2=0;
    for(int i=0;i<V.size();i++){
        if(V.at(i)==element1){
            count1++;
        }
        else if(V.at(i)==element2){
            count2++;
        }
    }
    if(count1>V.size()/3){
        output.push_back(element1);
    }
    if(count2>V.size()/3){
        output.push_back(element2);
    }
    return output;
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    vector<int> V;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        V.push_back(x);
    }
    vector<int> output=majorityElements(V);
    if(output.size()==0){
        cout<<"No majority elements "<<endl;
    }
    else{
        for(int i=0;i<output.size();i++){
            cout<<output.at(i)<<" ";
        }
    }
    return 0;
}