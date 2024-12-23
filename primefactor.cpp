#include<bits/stdc++.h>
using namespace std;
int primefactor(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
                cout<<i<<" ";   
            }
        }
    }
    if(n>1){
        cout<<n;
    }
    return 0;
}   
int main(){
    // Your code here
    int n;
    cin>>n;
    primefactor(n);

    return 0;
}