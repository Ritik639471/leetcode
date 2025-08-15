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
    TreeNode* help(vector<int>& pre,int i,int j){
        if(i>j) return NULL;
        int l=i+1;
        TreeNode* node=new TreeNode(pre[i]);
        while(l<=j&&pre[l]<pre[i]) l++;
        node->left=help(pre,i+1,l-1);
        node->right=help(pre,l,j);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return help(preorder,0,n-1);
    }
};