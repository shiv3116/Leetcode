typedef long long int ll;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<int> pq;
        ll sum = 0;
        for(int i=0;i<n;i++)
        {
            pq.push(target[i]);
            sum += target[i];
        }
        while(pq.top()>1)
        {
            sum -= pq.top();
            if(sum<=0 || sum>=pq.top())
                return false;
            
            int newel = pq.top()%sum;
            if(sum!=1 && newel==0)
                return false;
            sum += newel;
            pq.push(newel);
            pq.pop();
        }
        return true;
    }
};