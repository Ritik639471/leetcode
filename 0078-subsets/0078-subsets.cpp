class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans(pow(2,n));
        for(int i=0;i<ans.size();i++){
            vector<int>v;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    v.push_back(nums[j]);
                }
            }
            ans[i]=v;
        }
        return ans;
    }
};