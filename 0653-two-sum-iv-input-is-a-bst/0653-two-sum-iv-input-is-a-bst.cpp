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
    void help(TreeNode* root,deque<int>&q){
        if(root==NULL) return ;
        help(root->left,q);
        if(q.empty())  q.push_front(root->val);
        else q.push_back(root->val);
        help(root->right,q);
    }
    bool findTarget(TreeNode* root, int k) {
        deque<int>q;
        help(root,q);
        int a=0;
        while(q.size()>1){
            a=q.front();
            q.pop_front();
            while(!q.empty()&&k-a<q.back()) q.pop_back();
            if(!q.empty()&&k-a==q.back()){
                return true;
            }
        }
        return false;
    }
};