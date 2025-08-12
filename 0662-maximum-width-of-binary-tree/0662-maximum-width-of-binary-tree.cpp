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
private:
    void help(map<long,long>&mp,map<long,long>&mp1,TreeNode* root,long j,int i,int& ans){
        cout<<j<<" "<<i<<endl;
        if(root==NULL) return;
        if(mp[i]==0) mp[i]=j+1;
        if(mp1[i]==0) mp1[i]=j+1;
        mp[i]=min(mp[i],j+1);
        mp1[i]=max(mp1[i],j+1);
        j-=mp[i]-1;
        ans=max(ans,(int)(mp1[i]-mp[i]+1));
        help(mp,mp1,root->left,2*j,i+1,ans);
        help(mp,mp1,root->right,2*j+1,i+1,ans);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        map<long,long>mp,mp1;
        int ans=1;
        help(mp,mp1,root,0,0,ans);
        return ans;
    }
};