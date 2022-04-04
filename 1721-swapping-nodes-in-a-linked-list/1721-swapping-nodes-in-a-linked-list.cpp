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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *tmp = head;
        int len = 0;
        while(tmp!=NULL)
        {
            len++;
            tmp = tmp->next;
        }
        tmp = head;
        for(int i=1;i<k;i++)
        {
            tmp = tmp->next;
        }
        ListNode *n1 = tmp;
        tmp = head;
        for(int i=1;i<=len-k;i++)
        {
            tmp = tmp->next;
        }
        swap(n1->val,tmp->val);
        return head;
    }
};