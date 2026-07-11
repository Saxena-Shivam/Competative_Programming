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
void revrse(stack<int>&st){
    if(st.empty()){
        return ;
    }
    int temp=st.top();
    st.pop();
    revrse(st);
    insertAtBotom(st,temp);
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
    stack<int>st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    printStack(st);
    cout<<endl;
    revrse(st);
    printStack(st);
    cout<<endl;
    return 0;
}