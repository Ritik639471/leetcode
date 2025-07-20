class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0,an=0;
        vector<unordered_set<int>>s(n);
        for(int i=0;i<edges.size();i++){
            s[edges[i][0]].insert(edges[i][1]);
            s[edges[i][1]].insert(edges[i][0]);
        }
        unordered_map<int,bool>m;
        queue<int>q;
        for(int i=0;i<n;i++){
            long long j=0;
            if(m[i]) continue;
            q.push(i);
            m[i]=true;
            j+=1;
            while(!q.empty()){
                int a=q.front();
                q.pop();
                for(int c:s[a]){
                    if(!m[c]){
                        q.push(c);
                        m[c]=true;
                        j++;
                    }
                }
            }
            ans+=j*an;
            an+=j;
        }
        return ans;
    }
};