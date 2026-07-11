#include<stdio.h>
#include<stdlib.h>
struct Node insertion(struct Node *head,int value,int data){
    if(head==NULL) return head;
    
}
struct Node{
    int data;
    struct Node* next;
}node1,node2,node3;
int main(){
  node1.data=10;
  node2.data=20;
  node3.data=30;
  node1.next=node2;
  node2.next=node3;
  node3.next=NULL;
  struct Node *head=node1;
  
}