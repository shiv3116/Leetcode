/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        int l1=0,l2=0;
        while(t1!=NULL)
        {
            l1++;
            t1 = t1->next;
        }
        while(t2!=NULL)
        {
            l2++;
            t2 = t2->next;
        }
        if(l1==l2)
        {
            t1 = headA;
            t2 = headB;
            while(t1!=NULL && t2!=NULL)
            {
                if(t1==t2)
                    return t1;
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        else if(l1<l2)
        {
            t1 = headA;
            t2 = headB;
            for(int i=1;i<=(l2-l1);i++)
            {
                t2 = t2->next;
            }
            while(t1!=NULL && t2!=NULL)
            {
                if(t1==t2)
                    return t1;
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        else if(l2<l1)
        {
            t1 = headA;
            t2 = headB;
            for(int i=1;i<=(l1-l2);i++)
            {
                t1 = t1->next;
            }
            while(t1!=NULL && t2!=NULL)
            {
                if(t1==t2)
                    return t1;
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        return NULL;
    }
};