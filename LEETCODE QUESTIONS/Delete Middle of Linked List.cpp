// Delete the Middle Node of a Linked List
// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // if list is empty
        if(head==NULL)
        {
            return NULL;
        }
        // if list has only 1 element, delete it and return NULL
        if(head->next==NULL)
        {
            delete head;
            return NULL;
        }
        ListNode*slow = head;
        ListNode*fast = head;
        ListNode*prevOfSlow = head;    
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // after coming out of this while loop, slow is standing at the middle node
        while(prevOfSlow->next!=slow)
        {
            prevOfSlow = prevOfSlow->next;
        }
        // after coming out of this while loop, prevOfSlow will be standing just a node previous to our middle i.e.slow node, this will help us in deleting middle i.e. slow node
        prevOfSlow->next = slow->next;
        slow->next=NULL;
        delete slow;
        return head;
    }
};

// Input: head = [1,3,4,7,1,2,6]
// Output: [1,3,4,1,2,6]

// Input: head = [1,2,3,4]
// Output: [1,2,4]

// Input: head = [2,1]
// Output: [2]

// Input: head = [1]
// Output: NULL