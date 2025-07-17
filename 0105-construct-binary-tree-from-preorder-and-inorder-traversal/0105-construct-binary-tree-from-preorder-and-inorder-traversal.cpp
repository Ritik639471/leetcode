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
    int n;
    map<int,bool>mp;
    TreeNode* help(vector<int>& pre, vector<int>& in,int i,int j,int k){
        if(j>k) return NULL;
        TreeNode* t=new TreeNode(pre[i]);
        mp[pre[i]]=true;
        if(j==k) return t;
        int l;
        for(l=j;l<=k;l++){
            if(in[l]==pre[i]) break;
        }
        t->left=help(pre,in,i+1,j,l-1);
        int a;
        for(a=i;a<n;a++) if(!mp[pre[a]]) break;
        if(a<n) t->right=help(pre,in,a,l+1,k);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n=preorder.size();
        return help(preorder,inorder,0,0,n-1);
    }
};