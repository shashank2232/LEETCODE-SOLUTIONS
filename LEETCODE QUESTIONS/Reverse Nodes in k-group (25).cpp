// Reverse Nodes in k-Group Part-1
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    // if list is empty, return head
        if(head==NULL)
        {
            return head;
        }
        // now reverse the first k nodes and apply recursion on the rest
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        int count = 1;
        while(curr!=NULL && count<=k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        // after coming out of this while loop, we have reversed our first k nodes, now if next!=NULL means there are more remaining
        // nodes to be reversed, so we will recursively reverse them and since our new head is prev,we'll return prev
        if(next!=NULL)
        {
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};


// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,5,4]