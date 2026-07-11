#include<bits/stdc++.h>
using namespace std;
class ListNode {
    public:
    int data;
    ListNode*next;
};
bool hasCycle(ListNode *head){
       ListNode *slow=head; 
       ListNode *fast=head;
       while(fast->next!=NULL){
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;   
        }
        if(fast ==slow){
            return true;
        }
    }
    return false;
}
int main(){
    // Your code here
    return 0;
}