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
    TreeNode* help(vector<int>& pos, vector<int>& in,int i,int j,int k){
        if(j>k||i<0||mp[pos[i]]) return NULL;
        TreeNode* t=new TreeNode(pos[i]);
        mp[pos[i]]=true;
        if(j==k) return t;
        int l;
        for(l=j;l<=k;l++){
            if(in[l]==pos[i]) break;
        }
        t->left=help(pos,in,i-k+l-1,j,l-1);
        t->right=help(pos,in,i-1,l+1,k);
        return t;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n=postorder.size();
        return help(postorder,inorder,n-1,0,n-1);
    }
};