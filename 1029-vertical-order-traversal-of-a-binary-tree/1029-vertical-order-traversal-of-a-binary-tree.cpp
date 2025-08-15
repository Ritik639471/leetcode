/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            map<int,multiset<int>>mp1;
            int s=q.size();
            for(int i=0;i<s;i++){
                auto c=q.front();
                q.pop();
                mp1[c.second].insert(c.first->val);
                if(c.first->left) q.push({c.first->left,c.second-1});
                if(c.first->right) q.push({c.first->right,c.second+1});
            }
            for(auto c:mp1){
                for(auto d:c.second){
                    mp[c.first].push_back(d);
                }
            }
        }
        
        vector<vector<int>>ans(mp.size());
        int i=0;
        for(auto c:mp){
            ans[i++]=c.second;
        }
        return ans;
    }
};