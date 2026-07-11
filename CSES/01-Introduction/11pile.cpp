#include<iostream>
using namespace std;
string solve(long long  a,long long  b){
    if(b<a)swap(a,b);
    if(a==0&&b==0)return "YES";
    else if(b>2*a)return "NO";
    else if((a==b)&&((a%2)==0)) return "NO";
    else return "Yes";
}
int main(){
   int t;cin>>t;
   while(t--){
    long long a,b;
    cin>>a>>b;
    cout<<solve(a,b)<<endl;
   }
}