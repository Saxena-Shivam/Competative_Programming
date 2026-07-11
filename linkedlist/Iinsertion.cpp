#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){
        this->data=0;
        this ->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void printLL(Node*head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int findlength(Node *head){
    int len=0;
    Node *temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertathead(Node *&head,Node*tail,int data){
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
                
    }else{
        Node*newNode=new Node(data);
        newNode->next=head;
        head=newNode;
    }

}
void insertattail(Node *&head,Node*tail,int data){
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
                
    }
    else{
        Node*newNode=new Node(data);
        tail->next=newNode;
        tail=newNode;
    }

}
void Insertion(Node*&head,Node*&tail,int data,int pos){
    int len=findlength(head);
    if(head==tail){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else if(pos==1){
        insertathead(head,tail,data);
    }
    else if(pos==len+1){
        insertattail(head,tail,data);
    }
    else if(pos<len+1){
        Node *prev=NULL;
        Node *curr=head;
        while(pos!=1){
            prev=curr;
            curr=curr->next;
            pos--;
        }
        Node *newNode=new Node(data);
        prev->next=newNode;
        newNode->next=curr;
    }
    else {
        cout<<"Enetr correct position"<<endl;
    }
}
int main(){
    // Your code here
    Node*head=NULL;
    Node*tail=NULL;   
    insertathead(head, tail,50); 
    insertathead(head, tail,40);
    insertathead(head, tail,30);
    insertathead(head,tail, 20);
    insertathead(head, tail,10);
    Insertion(head,tail,60,6);
    printLL(head);
    return 0;
}