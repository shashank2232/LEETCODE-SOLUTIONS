// Reverse Nodes in k-Group  (Part 2)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    // if list is empty, return head
        if(head==NULL)
        {
            return head;
        }
        // first we'll calculate the length of our linked list
        int totalLen = 0;
        ListNode*temp = head;
        while(temp!=NULL)
        {
            totalLen++;
            temp = temp->next;
        }
        // now we'll reverse the first k nodes of our list
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
        }   // the first k nodes are reversed now
        
        // now if our next isn't NULL && we have k nodes to reverse i.e. (length-count+1) will tell us total remaining nodes,
        //  if its >= to k, only then we'll reverse our nodes, otherwise we'll simply make our head's next point to next 
        //  and finally return prev which is our new head
        if(next!=NULL && (totalLen-count+1)>=k)
        {
            head->next = reverseKGroup(next,k);
        }
        else{
            head->next = next;
        }
        return prev;
    }
};



// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]