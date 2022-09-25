class MyCircularQueue {
public:
    vector<int> queue;
    int front, rear;
    MyCircularQueue(int k) {
        queue.assign(k,-1);
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if(front==0 && rear==queue.size()-1 || rear==front-1)
        {
            return false;
        }
        if(front==-1)
        {
            front++;
            rear++;
            queue[rear] = value;
        }
        else
        {
            rear = (rear+1)%queue.size();
            queue[rear] = value;
        }
        return true;
    }
    
    bool deQueue() {
        if(front==-1)
            return false;
        if(front==rear)
        {
            front = rear = -1;
        }
        else
        {
            if(front==queue.size()-1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }
        return true;
    }
    
    int Front() {
        if(front==-1)
            return -1;
        return queue[front];
    }
    
    int Rear() {
        if(front==-1)
            return -1;
        return queue[rear];
    }
    
    bool isEmpty() {
        if(front==-1)
            return true;
        return false;
    }
    
    bool isFull() {
        if(front==0 && rear==queue.size()-1 || rear==front-1)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */