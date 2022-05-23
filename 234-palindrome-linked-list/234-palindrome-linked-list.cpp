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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head!=NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* tmp = head;
        int len = 0;
        while(tmp!=NULL)
        {
            tmp = tmp->next;
            len++;
        }
        if(len==2)
        {
            if(head->val==head->next->val)
                return true;
            return false;
        }
        len = len/2;
        tmp = head;
        while(len--)
        {
            tmp = tmp->next;
        }
        // cout<<tmp->val;
        tmp = reverse(tmp);
        // cout<<tmp->val;
        ListNode* t = head;
        while(tmp!=NULL)
        {
            if(t->val!=tmp->val)
                return false;
            tmp = tmp->next;
            t = t->next;
        }
        return true;
    }
};