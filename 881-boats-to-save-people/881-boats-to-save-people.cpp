class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans = 0,i=0,j=people.size()-1,sum=people[j];
        while(i<j)
        {
            if(people[j]+people[i]<=limit)
            {
                ans++;
                i++;
                j--;
            }
            else if(people[i]+people[j]>limit)
            {
                ans++;
                j--;
            }
            if(i==j)
            {
                ans++;
                break;
            }
        }
        return ans;
    }
};