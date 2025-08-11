class Solution {
private:
  int time=0;
void help(vector<vector<int>>&ans,vector<bool>&vis,vector<vector<int>>&ed,vector<vector<int>>&val,int i,int j){
    vis[i]=true;
    time++;
    val[i][0]=time;
    val[i][1]=time;
    for(auto b:ed[i]){
        if(b==j) continue;
        if(!vis[b]){
            help(ans,vis,ed,val,b,i);
            val[i][0]=min(val[i][0],val[b][0]);
            if(val[b][0]>val[i][1]){
                ans.push_back({i,b});
            }
        }else{
            val[i][0]=min(val[i][0],val[b][0]);
        }
    }
}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
        vector<vector<int>>ed(n);
        for(auto c:connections){
            ed[c[0]].push_back(c[1]);
            ed[c[1]].push_back(c[0]);
        }
        vector<bool>vis(n);
        vector<vector<int>>val(n,vector<int>(2, 0));
        help(ans,vis,ed,val,0,-1);
        return ans;
    }
};