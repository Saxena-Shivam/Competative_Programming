#include<iostream>
using namespace std;
const int MOD=1e9+7;
int noof5(int n){
    int ct=0;
    while(n>0){
        ct+=n/5;
        n/=5;
    }
   return ct;
}
int main(){
    int n;cin>>n;
    cout<<noof5(n)<<endl;
}