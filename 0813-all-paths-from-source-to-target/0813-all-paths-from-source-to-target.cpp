class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        vector<int>v;
        queue<pair<int,vector<int>>>q;
        q.push({0,v});
        while(!q.empty()){
            auto d=q.front();
            q.pop();
            d.second.push_back(d.first);
            if(d.first==n-1){
                ans.push_back(d.second);
                continue;
            }
            for(auto c:graph[d.first]){
                q.push({c,d.second});
            }
        }
        return ans;
    }
};