#include<bits/stdc++.h>
typedef long long ll;
#define all(x) x.begin(), x.end()
using namespace std;
int main(){
    string s;cin>>s;
    unordered_map<char,int>mp;
    for(auto c:s) mp[c]++;
    string prev="",next="";
    char oddchar=' ';
    int oddcount=0;
    for(auto p:mp){
        if(p.second&1) {
            oddcount++;
            oddchar=p.first;
        }
    }
    if(oddcount>1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    for(auto p:mp){
        if(p.first==oddchar) continue;
        while(p.second--){
            if(p.second&1) prev+=p.first;
            else next+=p.first;
        }
    }
    string ans=prev;
    if(oddchar!=' ') {
       while(mp[oddchar]--) ans+=oddchar;
    }
    reverse(all(next));
    ans+=next;
    cout<<ans<<endl;
}