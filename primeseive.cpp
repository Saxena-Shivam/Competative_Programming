#include<bits/stdc++.h>
using namespace std;
int N=1000000;
vector<int> prime(N,1);   
int primeseive(){
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i){
                prime[j]=0;
            }
        }
    }
    return 0;
}
int main(){
    // Your code here
    primeseive();
    for(int i=0;i<N;i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}