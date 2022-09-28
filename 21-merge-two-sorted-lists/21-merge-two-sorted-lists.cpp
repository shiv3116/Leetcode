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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *t = dummy;
        ListNode *tmp1 = list1;
        ListNode *tmp2 = list2;
        while(tmp1!=NULL && tmp2!=NULL)
        {
            if(tmp1->val<=tmp2->val)
            {
                t->next = tmp1;
                tmp1 = tmp1->next;
            }
            else
            {
                t->next = tmp2;
                tmp2 = tmp2->next;
            }
            t = t->next;
        }
        while(tmp1!=NULL)
        {
            t->next = tmp1;
            tmp1 = tmp1->next;
            t = t->next;
        }
        while(tmp2!=NULL)
        {
            t->next = tmp2;
            tmp2 = tmp2->next;
            t = t->next;
        }
        return dummy->next;
    }
};