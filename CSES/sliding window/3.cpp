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
    int xo=0;
    for(int i=0;i<k;i++)xo^=v[i];
    int xo1=xo;
    for(int i=k;i<n;i++){
        xo^=v[i]^v[i-k];
        xo1^=xo;
    }
    cout<<xo1<<endl;
    return 0;
}