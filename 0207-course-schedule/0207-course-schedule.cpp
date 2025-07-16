class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pq) {
        unordered_map<int, bool> m;
        unordered_map<int, set<int>> s, s1;
        for (int i = 0; i < pq.size(); i++) {
            s[pq[i][0]].insert(pq[i][1]); //depends
            s1[pq[i][1]].insert(pq[i][0]); //dependents
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (m[i] || s[i].empty()){
                m[i] = true;
            q.push(i);}
        }
        while(!q.empty()){
            int a=q.front();
            m[a]=true;
            q.pop();
            for(auto c: s1[a]){
                s[c].erase(a);
                if(s[c].empty()&&!m[c]) q.push(c);
            }
        }
        for (int i = 0; i < n; i++) {
            if(!m[i]) return m[i];
        }
        return true;;
    }
};