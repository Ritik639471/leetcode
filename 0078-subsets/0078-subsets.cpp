class Solution {
public:
    void sub(vector<int>& nums,vector<vector<int>>& ans,vector<int> v,int i){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        sub(nums,ans,v,1+i);
        v.push_back(nums[i]);
        sub(nums,ans,v,1+i);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sub(nums,ans,v,0);
        return ans;
    }
};