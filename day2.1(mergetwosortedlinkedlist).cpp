 //////mera logic ////////////
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         // Dummy head to start the merged list
//         ListNode* head = new ListNode();
//         ListNode* tail = head; // Added a tail pointer to build the list properly
        
//         ListNode* temp1 = list1;
//         ListNode* temp2 = list2;
        
//         while (temp1 != NULL && temp2 != NULL) {
//             if (temp1->val <= temp2->val) { // Fixed comparison order for ascending merge
//                 ListNode* connect1 = temp1;
//                 tail->next = connect1;
//                 tail = connect1;
//                 temp1 = temp1->next;
//             } else {
//                 ListNode* connect2 = temp2;
//                 tail->next = connect2;
//                 tail = connect2;
//                 temp2 = temp2->next;
//             }
//         }
        
//         // Attach the remaining elements from whichever list is left over
//         if (temp1 != NULL) {
//             tail->next = temp1;
//         } else if (temp2 != NULL) {
//             tail->next = temp2;
//         }
        
//         // Optional print logic (kept from your code)
//         ListNode* temp = head->next;
//         while (temp != NULL) {
//             cout << temp->val << " ";
//             temp = temp->next;
//         }
        
//         // Return the actual head of the merged list (skipping the dummy node)
//         return head->next;
//     }
// };

/////////////optimalsolution//////////
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a head node to act as the start of the merged list
        ListNode* head= new ListNode(0);
        
        // Use a 'temp' pointer to build the new list
        ListNode* temp = head;
        
        // Traverse both lists until we reach the end of one of them
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;    // Point to list1's node
                list1 = list1->next;      // Move list1 forward
            } else {
                temp->next = list2;    // Point to list2's node
                list2 = list2->next;      // Move list2 forward
            }
            // Move the temp pointer forward to the new end of the merged list
            temp = temp->next;
        }
        
        // If one of the lists still has nodes left, just attach the rest of it
        if (list1 != NULL) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        
        // Save the actual head of the merged list (skipping the head node)
        ListNode* mergedHead = head->next;
        
        // Delete the head node to prevent memory leaks
        delete head;
        
        return mergedHead;
    }
};
