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
        vector<int> arr;
        ListNode *tmp = head;
        while(tmp!=NULL)
        {
            arr.push_back(tmp->val);
            tmp = tmp->next;
        }
        swap(arr[k-1],arr[arr.size()-k]);
        ListNode *newHead = new ListNode(arr[0]);
        tmp = newHead;
        for(int i=1;i<arr.size();i++)
        {
            ListNode *t = new ListNode(arr[i]);
            tmp->next = t;
            tmp = tmp->next;
        }
        return newHead;
    }
};