#include <bits/stdc++.h>
using namespace std;
int main(){
       int n;cin>>n;
       int x;cin>>x;
       vector<int>v(n+1);
       for(int i=1;i<=n;i++){
           cin>>v[i];
       }
       sort(v.begin(),v.end());
       int i=1,j=n,ct=0;
      while(i<j){
          if(v[i]+v[j]<=x){
              i++;
              j--;
              ct++;
          }
          else{
              j--;
          }
      }
       int ans=n-2*ct;
       ans+=ct;
       cout<<ans<<endl;
    return 0;
}
