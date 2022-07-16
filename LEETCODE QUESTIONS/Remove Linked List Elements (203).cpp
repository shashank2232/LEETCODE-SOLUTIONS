// Remove Linked List Elements
// Given the head of a linked list and an integer val,
// remove all the nodes of the linked list that has Node.val == val, and return the new head.
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // creating a new node and pointing its next to head
       ListNode* dummy = new ListNode;
        dummy -> next = head;
        ListNode* curr = dummy;    // putting curr on dummy which is behind head node
        
        while(curr -> next!=NULL) {
            if(curr -> next -> val == val) {
                curr -> next = curr -> next -> next;
            } else {
                curr = curr -> next;
            }
        }
        
        return dummy -> next;
    }
};

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]

// Input: head = [], val = 1
// Output: []

// Input: head = [7,7,7,7], val = 7
// Output: []