#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    if(n==1)cout<<1<<endl;
    else if(n==2||n==3)cout<<"NO SOLUTION"<<endl;
    else if (n==4)cout<<2<<" "<<4<<" "<<1<<" "<<3<<endl;
    else{
        int temp=(n+1)/2;
        int l=temp;
        for(int i=1;i<=l||temp<n;){
            if(i<=l)cout<<i++<<" ";
            if(temp<n)cout<<++temp<<" ";
        }
        cout<<endl;
    }
}