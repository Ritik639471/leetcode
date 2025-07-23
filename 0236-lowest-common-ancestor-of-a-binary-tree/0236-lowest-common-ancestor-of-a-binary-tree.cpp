/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool help(TreeNode* root,TreeNode* p){
        if(root==NULL) return false;
        if(root->val==p->val) return true;
        return help(root->left,p)||help(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val||root->val==q->val) return root;
        bool r1,r2,l1,l2;
        r1=help(root->right,p);
        r2=help(root->right,q);
        l1=help(root->left,p);
        l2=help(root->left,q);
        if(r1&&l2||r2&&l1) return root;
        else if(r1&&r2) return lowestCommonAncestor(root->right,p,q);
        else return lowestCommonAncestor(root->left,p,q);
    }
};