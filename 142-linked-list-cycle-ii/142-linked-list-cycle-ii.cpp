class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return NULL;
        }
        unordered_map<ListNode*,int> m;
        ListNode *tmp = head;
        int flag = 1;
        while(1)
        {
            if(m.find(tmp)==m.end())
            {
                m[tmp]++;
                if(tmp->next!=NULL)
                {
                    tmp = tmp->next;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if(flag==0)
        {
            return NULL;
        }
        return tmp;
    }
};