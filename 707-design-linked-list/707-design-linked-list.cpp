class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode *head = NULL;
    MyLinkedList() {
    }
    
    int get(int index) {
        int c = index;
        ListNode *tmp = head;
        int len = 0;
        while(tmp!=NULL)
        {
            len++;
            tmp = tmp->next;
        }
        if(index<0 || index>len-1)
            return -1;
        tmp = head;
        while(c>0)
        {
            tmp = tmp->next;
            c--;
        }
        return tmp->val;
    }
    
    void addAtHead(int val) {
        if(head==NULL)
        {
            head = new ListNode(val);
        }
        else
        {
            ListNode *tmp = new ListNode(val);
            tmp->next = head;
            head = tmp;
        }
    }
    
    void addAtTail(int val) {
        if(head==NULL)
        {
            head = new ListNode(val);
            return;
        }
        ListNode *tmp = head;
        while(tmp->next!=NULL)
        {
            tmp = tmp->next;
        }
        ListNode *add = new ListNode(val);
        tmp->next = add;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0)
        {
            ListNode *t = new ListNode(val);
            t->next = head;
            head = t;
            return;
        }
        int len = 0;
        int c = index-1;
        ListNode *tmp = head;
        while(tmp!=NULL)
        {
            len++;
            tmp = tmp->next;
        }
        if(index>len || index<0)
            return;
        tmp = head;
        while(c>0)
        {
            tmp = tmp->next;
            c--;
        }
        ListNode *n = tmp->next;
        ListNode *add = new ListNode(val);
        tmp->next = add;
        tmp->next->next = n;
    }
    
    void deleteAtIndex(int index) {
        if(index==0)
        {
            head = head->next;
            return;
        }
        int c = index-1;
        int len = 0;
        ListNode *tmp = head;
        while(tmp!=NULL)
        {
            len++;
            tmp = tmp->next;
        }
        if(index>len-1 || index<0)
            return;
        tmp = head;
        while(c--)
        {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */