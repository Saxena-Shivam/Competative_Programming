#include<stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
    
};
void printLL(struct Node*head){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int length(struct Node *head){
    struct Node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
struct Node* insertatnode(struct Node*head,int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    return newnode;
   
}
struct Node* insertattail(struct Node*head,int data){
    struct Node*temp=head;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next=NULL;
    if(head==NULL) return newnode;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head; 
}
void insertatnodenoreturn(struct Node**head,int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
   
}
void insertattailnoreturn (struct Node**head,int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next=NULL;
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct Node*temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newnode; 
}
struct Node* insertion(struct Node*head,int data,int position){
    struct Node *temp=head;
    int len=length(head);
    if(position<=1){
        return insertatnode(head,data);
    }
    else if(position>len){
        return insertattail(head,data);
    }
    else{
        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=data;
        while(position>2&&temp->next!=NULL){
            position--;
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return head;
    }
}
struct Node* insertionbeforevalue(struct Node*head,int data,int value){
        if (head==NULL)return head;
        if(head->data==value){
            return insertatnode(head,data);
        }
        struct Node *temp=head;
        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=data;
        while((temp->next->data!=value)&&(temp->next!=NULL)){
            temp=temp->next;
        }
        if(temp->next!=NULL){
            newnode->next=temp->next;
            temp->next=newnode;
        }
        else{
            free(newnode);
        }
        return head;
}
struct Node* insertionaftervalue(struct Node* head, int data, int value) {
    struct Node* temp = head;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp != NULL) {
        newnode->next = temp->next;
        temp->next = newnode;
    } 
    else {
        free(newnode);
    }
    return head;
}

int main(){
    struct Node node1,node2,node3,node4;
    node1.data=100;
    node2.data=200;
    node3.data=300;
    node4.data=400;
    node1.next=&node2;
    node2.next=&node3;
    node3.next=&node4;
    node4.next=NULL;
    struct  Node *head;
    head=&node1;
    int size=length(head);
    printf("%d\n",size);
    printLL(head);
    head=insertatnode(head,50);
    printLL(head);
    head=insertattail(head,500);
    printLL(head);
    insertattailnoreturn(&head,600);
    printLL(head);
    insertatnodenoreturn(&head,40);
    printLL(head);
    head=insertion(head,150,4);
    printLL(head);
    head=insertion(head,700,10);
    printLL(head);
    head=insertionbeforevalue(head,450,400);
    printLL(head);
    head=insertionbeforevalue(head,30,40);
    printLL(head);
    head=insertionaftervalue(head,800,700);
    printLL(head);
    return 0;

}
