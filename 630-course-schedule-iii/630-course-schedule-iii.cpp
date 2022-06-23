class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        int ans = 0, days = 0;
        priority_queue<int> q;
        for(int i=0;i<courses.size();i++)
        {
            // cout<<courses[i][0]<<" "<<courses[i][1]<<'\n';
            if(days+courses[i][0]<=courses[i][1])
            {
                ans++;
                days += courses[i][0];
                q.push(courses[i][0]);
            }
            else
            {
                if(!q.empty() && q.top()>courses[i][0])
                {
                    days -= q.top();
                    q.pop();
                    days += courses[i][0];
                    q.push(courses[i][0]);
                }
            }
        }
        return ans;
    }
};