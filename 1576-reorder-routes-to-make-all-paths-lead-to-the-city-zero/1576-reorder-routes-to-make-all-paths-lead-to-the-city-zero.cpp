class Solution {
public:
    int minReorder(int n, vector<vector<int>>& cs) {
        vector<vector<int>>e(n),e1(n);
        for(int i=0;i<n-1;i++){
            e[cs[i][0]].push_back(cs[i][1]);
            e1[cs[i][1]].push_back(cs[i][0]);
        }
        queue<int>q;
        q.push(0);
        vector<bool>m(n);
        m[0]=true;
        int ans=0;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto c:e1[a]){
               if(!m[c]) {q.push(c);m[c]=true;}
            }
            for(auto c:e[a]){
                if(!m[c]) {q.push(c);m[c]=true;ans++;}
            }
        }
        return ans;
    }
};