class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int n=t.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            while(!q.empty()&&t[i]>q.top().first){
                ans[q.top().second]=i-q.top().second;
                q.pop();
            }
            q.push({t[i],i});
        }
        return ans;
    }
};