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
    bool f=true;
    int help(TreeNode* root){
        if(!root) return 0;
        int r=help(root->right),l=help(root->left);
        if(abs(l-r)>1) f=false;
        return max(1+r,1+l);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return (abs(help(root->left)-help(root->right))<=1) && f;
    }
};