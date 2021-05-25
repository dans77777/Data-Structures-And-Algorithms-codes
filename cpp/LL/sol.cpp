/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;


        while(head != NULL)
        {
		// if the head node value equals to the values of the next node then we have a duplicate
            if(head->next != NULL && head->val == head->next->val)
            {
			// move the head node until there is nomore a duplicate, also be mindful of the bounary check
                while(head->next != NULL && head->val == head->next->val)
                {
                    head = head->next;
                }
				// now head will be at the last node of the duplicate node so we do head next
                res->next = head->next;
            } else {
			// if the duplicate condition doesn't pass we know the node itself is unique
                res->next = head;
                res = res->next;
            }
            head = head->next;
        }
	// return the sentinel node
        return dummy->next;
    }
};
