#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    // Your code here
    int n,k;cin>>n>>k;
    int x,a,b,c;cin>>x>>a>>b>>c;
    vector<int>v(n);
    v[0]=x;
    for(int i=1;i<n;i++){
        v[i]=(a*v[i-1]+b)%c;
    }
    int sum=0;
    for(int i=0;i<k;i++)sum+=v[i];
    int xo=sum;
    for(int i=k;i<n;i++){
        sum+=v[i]-v[i-k];
        xo^=sum;
    }
    cout<<xo<<endl;
    return 0;
}