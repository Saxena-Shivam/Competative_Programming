#include<bits/stdc++.h>
using namespace std;
int middle(stack<int>st,int position){
     if(position==1){
       return st.top(); 
     } 
     int temp=st.top();
     st.pop();
     int ans=middle(st,--position);
     st.push(temp);
     return ans;
}
int main(){
    // Your code here
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int position=3;
    cout<< middle(st,position);
    return 0;
}