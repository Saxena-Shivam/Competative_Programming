#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    set<int>mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp.insert(x);
    }
    cout<<mp.size()<<endl;
    return 0;
}
