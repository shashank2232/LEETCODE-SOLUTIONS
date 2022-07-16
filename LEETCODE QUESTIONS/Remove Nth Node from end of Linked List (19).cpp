// Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        {
            return head;
        }
        int len = 0;
        ListNode*temp = head;
        while(temp!=NULL)
        {
            len++;
            temp = temp->next;
        }
        delete temp;
        if(n==len)
        {
            return head->next;
        }
        int count = len-n;              // node at this position is to be deleted
        ListNode*temp2 = head;
        int counter=1;
        while(counter!=count)
        {
            counter++;
            temp2 = temp2->next;
            
        }
        ListNode*todelete = temp2->next;
        temp2->next = temp2->next->next;
        delete todelete;
        return head;
        
    }
};


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Input: head = [1], n = 1
// Output: []

// Input: head = [1,2], n = 1
// Output: [1]