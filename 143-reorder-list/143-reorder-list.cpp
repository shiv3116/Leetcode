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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;
        stack<ListNode*> st;
        ListNode *tmp = head;
        int sz = 0;
        while(tmp!=NULL)
        {
            st.push(tmp);
            tmp = tmp->next;
            sz++;
        }
        tmp = head;
        for(int i=0;i<sz/2;i++)
        {
            ListNode *t = tmp->next;
            tmp->next = st.top();
            tmp->next->next = t;
            tmp = tmp->next->next;
            st.pop();
        }
        tmp->next = NULL;
    }
};