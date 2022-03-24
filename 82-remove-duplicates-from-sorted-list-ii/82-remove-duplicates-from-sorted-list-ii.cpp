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
        ListNode *ans = new ListNode(0);
        ans->next = head;
        ListNode *tmp = ans;
        while(tmp->next!=NULL && tmp->next->next!=NULL)
        {
            if(tmp->next->val==tmp->next->next->val)
            {
                int d = tmp->next->val;
                while(tmp->next!=NULL && tmp->next->val==d)
                {
                    tmp->next = tmp->next->next;
                }
            }
            else
            {
                tmp = tmp->next;
            }
        }
        return ans->next;
    }
};