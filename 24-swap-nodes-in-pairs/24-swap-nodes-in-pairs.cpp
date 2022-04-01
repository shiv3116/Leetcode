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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        ListNode *tmp = head;
        ListNode *ans = head->next;
        ListNode *a1 = tmp;
        ListNode *a2 = tmp->next;
        ListNode *a3 = tmp->next->next;
        a2->next = a1;
        a1->next = a3;
        ListNode *prev = tmp;
        tmp = tmp->next;
        if(tmp!=NULL)
        {
            while(tmp->next!=NULL)
            {
                ListNode *t1 = tmp;
                ListNode *t2 = tmp->next;
                ListNode *t3 = tmp->next->next;
                t2->next = t1;
                t1->next = t3;
                prev->next = t2;
                prev = tmp;
                tmp = tmp->next;
                if(tmp==NULL)
                    break;
            }
        }
        return ans;
    }
};