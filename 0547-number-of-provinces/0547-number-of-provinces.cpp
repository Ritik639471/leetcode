class Solution {
public:
    int findCircleNum(vector<vector<int>>& isC) {
        int ans=0,n=isC.size(),a;
        vector<bool>vis(n);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            vis[i]=true;
            q.push(i);
            ans++;
            while(!q.empty()){
                a=q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(isC[a][j]&&!vis[j]){
                        q.push(j);
                        vis[j]=true;
                    }
                }
            }
        }
        return ans;
    }
};