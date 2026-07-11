#include<iostream>
using namespace std;
const int MOD=1e9+7;
int binExp(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=(ans*1LL*a)%MOD;
        a=(a*1LL*a%MOD);
        b>>=1;
    }
    return ans%MOD;
}
int main(){
    int n;cin>>n;
    cout<<binExp(2,n)<<endl;
}