// Rotate List 
// Given the head of a linked list, rotate the list to the right by k places.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // if list is empty,return head
        if(head==NULL)
        {
            return head;
        }
        // calculate the length of the list
        ListNode*temp = head;
        int length = 1;
        // now traverse till we reach last node and also get our length of the list
        while(temp->next!=NULL)
        {
            temp = temp->next;
            length++;
        }
        // now temp is standing at last node, point its next to head
        temp->next = head;
        k = k%length;              // this is done in case k is greater than length of the list
        k = length - k;            // this will make us reach to our new tail node OR last node of the list
        while(k>0)
        {
            temp = temp->next;
            k--;
        } // out of this loop, temp is standing at our new tail node,simply put head to its next and then make its next point to NULL
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]