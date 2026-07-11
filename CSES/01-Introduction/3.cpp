#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count=1,ct=1;
    for(int i=0;i<s.size();i++) {
        if(s[i]==s[i+1]){
            ct++;
        }
        else{
            count=max(count,ct);
            ct=1;
        }
        count=max(count,ct);
    }
    cout<<count<<endl;
    return 0;
}