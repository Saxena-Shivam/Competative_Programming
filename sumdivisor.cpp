#include<bits/stdc++.h>
using namespace std;
int N=1e7+7;
vector<long long> divsum(N,1);
int primefactor(int n){
    int p=n;
    divsum[p]+=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            divsum[p]+=i;
        }
    }
    if((n>1)&&(n!=p)){
        divsum[p]+=n;
    }
    divsum[p]+=divsum[p-1];
    return 0;
}
void computeDivisorSums() {
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divsum[j] += i;
        }
    }
    for (int i = 2; i < N; i++) {
        divsum[i] += divsum[i - 1];
    }
}
int main(){
    computeDivisorSums();
    for(int i=1;i<=5;i++){
        cout<<i<<" "<<divsum[i]<<endl;
    }
    return 0;
}