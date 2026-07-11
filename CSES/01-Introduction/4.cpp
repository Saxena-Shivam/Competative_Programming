#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long n;cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long op=0;
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            
            op+=(v[i-1]-v[i]);
            v[i]=v[i-1];
        }
    }
    cout<<op<<endl;
    return 0;
}