class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        vector<vector<string>> ans;
        unordered_map<string, set<int>> mp;
        for (int j = 0; j < a.size(); j++) {
            for (int i = 1; i < a[j].size(); i++) {
                mp[a[j][i]].insert(j);
            }
        }
        unordered_map<string, bool> m;
        unordered_map<int, bool> ac;
        queue<int> q;
        for (int i = 0; i < a.size(); i++) {
            if (ac[i])
                continue;
            ans.push_back({a[i][0]});
            int j = ans.size() - 1;
            q.push(i);
            ac[i] = true;
            while (!q.empty()) {
                int k = q.front();
                q.pop();
                for (int l = 1; l < a[k].size(); l++) {
                    if (m[a[k][l]] == false) {
                        ans[j].push_back(a[k][l]);
                        m[a[k][l]] = true;
                        auto c = mp[a[k][l]];
                        for (auto d : c) {
                            if (ac[d] == false){
                                q.push(d);
                                ac[d] = true;
                            }
                        }
                    }
                }
            }
            sort(ans[j].begin()+1, ans[j].end());
        }
        return ans;
    }
};