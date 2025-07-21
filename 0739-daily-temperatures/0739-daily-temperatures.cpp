class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>q;
        int n=t.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            while(!q.empty()&&t[i]>t[q.top()]){
                ans[q.top()]=i-q.top();
                q.pop();
            }
            q.push(i);
        }
        return ans;
    }
};