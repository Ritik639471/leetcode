class Solution {
public:
    void help(vector<vector<int>>& graph,int des,int s,vector<vector<int>>& ans,vector<int> v){
        v.push_back(s);
        if(s==des){
            ans.push_back(v);
        }
        for(auto c:graph[s]){
            help(graph,des,c,ans,v);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        help(graph,n-1,0,ans,{});
        return ans;
    }
};