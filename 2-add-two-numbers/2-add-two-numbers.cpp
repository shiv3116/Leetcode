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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l2;
        
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *ans = new ListNode();
        ListNode *res = ans;
        int carry = 0;
        while(t1!=NULL && t2!=NULL)
        {
            int a = t1->val;
            int b = t2->val;
            if(carry == 0)
            {
                int val;
                if(a+b>9)
                {
                    string s = to_string(a+b);
                    val = s[1]-'0';
                    carry = s[0]-'0';
                }
                else
                {
                    string s = to_string(a+b);
                    val = s[0]-'0';
                }
                ListNode *tmp = new ListNode(val);
                ans->next = tmp;
                ans = ans->next;
            }
            else
            {
                int val;
                if(a+b+carry>9)
                {
                    string s = to_string(a+b+carry);
                    val = s[1]-'0';
                    carry = s[0]-'0';
                }
                else
                {
                    string s = to_string(a+b+carry);
                    val = s[0]-'0';
                    carry = 0;
                }
                ListNode *tmp = new ListNode(val);
                ans->next = tmp;
                ans = ans->next;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1!=NULL)
        {
            int a = t1->val;
            if(carry==0)
            {
                ListNode *tmp = new ListNode(a);
                ans->next = tmp;
                ans = ans->next;
            }
            else
            {
                int val;
                if(a+carry>9)
                {
                    string s = to_string(a+carry);
                    val = s[1]-'0';
                    carry = s[0]-'0';
                }
                else
                {
                    string s = to_string(a+carry);
                    val = s[0]-'0';
                    carry = 0;
                }
                ListNode *tmp = new ListNode(val);
                ans->next = tmp;
                ans = ans->next;
            }
            t1 = t1->next;
        }
        while(t2!=NULL)
        {
            int a = t2->val;
            if(carry==0)
            {
                ListNode *tmp = new ListNode(a);
                ans->next = tmp;
                ans = ans->next;
            }
            else
            {
                int val;
                if(a+carry>9)
                {
                    string s = to_string(a+carry);
                    val = s[1]-'0';
                    carry = s[0]-'0';
                }
                else
                {
                    string s = to_string(a+carry);
                    val = s[0]-'0';
                    carry = 0;
                }
                ListNode *tmp = new ListNode(val);
                ans->next = tmp;
                ans = ans->next;
            }
            t2 = t2->next;
        }
        if(carry!=0)
        {
            ListNode *tmp = new ListNode(carry);
            ans->next = tmp;
            ans = ans->next;
        }
        return res->next;
    }
};