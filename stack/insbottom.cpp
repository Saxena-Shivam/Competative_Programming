#include<bits/stdc++.h>
using namespace std;
void insertAtBotom(stack<int>&st,int data){
    if(st.empty()){
        st.push(data);
        return ;
    }
    int temp=st.top();
    st.pop();
    insertAtBotom(st,data);
    st.push(temp);
}
void printStack(stack<int>&st){
    if(st.empty())return;
    int topElem=st.top();
    cout<<topElem<<" ";
    st.pop();
    printStack(st);
    st.push(topElem);
}
int main(){
    // Your code here 
    stack<int>st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    int data=1;
    printStack(st);
    cout<<endl;
    insertAtBotom(st,data);
    printStack(st);
    cout<<endl;
    return 0;
}