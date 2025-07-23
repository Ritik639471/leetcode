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
    int mx= INT_MIN;
    int help(TreeNode* root){
        if(root==NULL) return 0;
        int a=root->val,l=0,r=0;
        if(root->left){
            l=help(root->left);
            mx=max(mx,l);
        }
        if(root->right){
            r=help(root->right);
            mx=max(mx,r);
        }
        mx=max({mx,r+l+root->val,root->val});
        return max(root->val,root->val+max(r,l));
    }
    int maxPathSum(TreeNode* root) {
        mx=INT_MIN;
        return max(mx,help(root));
    }
};