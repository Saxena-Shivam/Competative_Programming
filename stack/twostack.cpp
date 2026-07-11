#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    Stack(int size){
        top1=-1;
        top2=size;
        this->size=size;
        arr=new int[size];
    
    }
    void push1(int data){
        if(top2-top1>1){
            top1++;
            arr[top1]=data;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }
    void push2(int data){
        if(top2-top1>1){
            top2--;
            arr[top2]=data;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }
    void pop1(){
        if(top1>=0){
            arr[top1]=0;
            top1--;
        }
        else cout<<"Underflow the stack is empty"<<endl;

    }
    void pop2(){
         if(top2<size){
            arr[top2]=0;
            top1++;
        }
        else cout<<"Underflow the stack is empty"<<endl;
    }
    void prints(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
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
    Stack st(5);
    st.prints();
    st.push2(1);
    st.prints();
    st.push1(2);
    st.prints();
    st.push1(3);
    st.prints();
    st.push2(4);
    st.prints();
    st.push2(5);
    st.prints();
    st.push2(6);
    st.prints();
    return 0;
}