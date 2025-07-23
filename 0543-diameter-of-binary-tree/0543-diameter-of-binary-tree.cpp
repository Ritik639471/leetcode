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
    int mx=0;
    int help(TreeNode* root){
        if(root==NULL) return 0;
        int l=help(root->left),r=help(root->right);
        mx=max(mx,r+l);
        return 1+max(r,l);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        mx=0;
        return max(mx,help(root)-1);
    }
};