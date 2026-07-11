// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode *temp1 = l1; // Pointer for list 1
//         ListNode *temp2 = l2; // Pointer for list 2
//         int len1 = 0, len2 = 0, s = 0;
        
//         // Calculate length of l1
//         while (temp1 != nullptr) {
//             len1++;
//             temp1 = temp1->next;
//         }
        
//         // Calculate length of l2
//         while (temp2 != nullptr) {
//             temp2 = temp2->next;
//             len2++;
//         }

//         temp1 = l1; // Reset temp1 to the start of l1
//         temp2 = l2; // Reset temp2 to the start of l2
        
//         ListNode dummy; // Dummy node to simplify result construction
//         ListNode *tail = &dummy; // Pointer to build the result list
//         int c = 0; // Carry
        
//         // Error: Incorrectly comparing l1 and l2 directly (should compare values or lengths)
//         if (l1 > l2) {
//             while (temp1 != nullptr || temp2 != nullptr) {
//                 // Incorrect logic here, should add both values if not null
//                 if (temp2 != nullptr) {
//                     s = temp1->val + c; // Only using temp1 value
//                 } else {
//                     s = temp1->val + temp2->val + c; // temp2 should not be null here
//                 }
//                 temp1->val = s % 10; // Modify input list directly (not correct)
//                 c = s / 10; // Update carry
//                 temp1 = temp1->next; // Move temp1 to the next node
//                 temp2 = temp2->next; // Move temp2 to the next node
//             }
//             if (c) {
//                 ListNode *newnode = new ListNode(c); // New node created but not added to result
//             }
//             return l1; // Returning modified l1 is not correct
//         } else {
//             while (temp2 != nullptr || temp1 != nullptr) {
//                 // Similar issues here as above
//                 if (temp1 != nullptr) {
//                     s = temp2->val + c; // Only using temp2 value
//                 } else {
//                     s = temp2->val + temp1->val + c; // temp1 should not be null here
//                 }
//                 temp2->val = s % 10; // Again modifying the input list directly
//                 c = s / 10; // Update carry
//                 temp1 = temp1->next; // Move temp1 to the next node
//                 temp2 = temp2->next; // Move te mp2 to the next node
//             }
//             if (c) {
//                 ListNode *newnode = new ListNode(c); // New node created but not added to result
//             }
//             return l1; // Returning modified l1 is not correct
//         }
//     }
// };
