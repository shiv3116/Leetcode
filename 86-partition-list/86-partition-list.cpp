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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *t1 = new ListNode(INT_MIN);
        ListNode *t2 = new ListNode(INT_MIN);
        ListNode *h1 = t1;
        ListNode *h2 = t2;
        ListNode *tmp = head;
        while(tmp!=NULL)
        {
            if(tmp->val<x)
            {
                ListNode *y = new ListNode(tmp->val);
                t1->next = y;
                t1 = t1->next;
            }
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp!=NULL)
        {
            if(tmp->val>=x)
            {
                ListNode *y = new ListNode(tmp->val);
                t2->next = y;
                t2 = t2->next;
            }
            tmp = tmp->next;
        }
        h1 = h1->next;
        h2 = h2->next;
        ListNode *ans;
        if(h1!=NULL)
        {
            ans = h1;
            while(h1->next!=NULL)
            {
                h1 = h1->next;
            }
            h1->next = h2;
        }
        else
        {
            ans = h2;
        }
        return ans;
    }
};