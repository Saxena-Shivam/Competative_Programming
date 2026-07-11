#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){
        this->next=NULL;
    }
    Node(int data){
        this->data= data;
        this->next=NULL;
    }

};
void printNode(Node*head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
void insert(Node*head ,int pos){

}
void countnode(Node *head){
    int count=0;
    Node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout<<count<<endl;
}
int main(){
    // Your code here
    Node *head=new Node(29);
    Node *second=new Node(30);
    Node *tail=new Node(38);
    head->next=second;
    second->next=tail;
    printNode(head);
    countnode(head);

    return 0;
}