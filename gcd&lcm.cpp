#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int gcd1(int a,int b){
    if(a%b==0){
        return b;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int main(){
    // Your code here
    int a,b;    
    cin>>a>>b;  
    cout<<gcd(a,b)<<" "<<lcm(a,b);
    return 0;
}