class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pq) {
        unordered_map<int,unordered_set<int>>s,s1;
        for(int i=0;i<pq.size();i++){
            s[pq[i][0]].insert(pq[i][1]);
            s1[pq[i][1]].insert(pq[i][0]);
        }
        vector<int>ans;
        unordered_map<int,bool>m;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (m[i] || s[i].empty()){
                m[i] = true;
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int a=q.front();
            m[a]=true;
            q.pop();
            for(auto c: s1[a]){
                s[c].erase(a);
                if(s[c].empty()&&!m[c]){ ans.push_back(c);q.push(c);}
            }
        }
        for (int i = 0; i < n; i++) {
            if(!m[i]) return {};
        }
        return ans;
    }
};