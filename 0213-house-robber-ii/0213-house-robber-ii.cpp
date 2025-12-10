class Solution {
public:
    int rob(vector<int>& nums) {
        int ans=0,n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[1],nums[0]);
        vector<int> dp(n + 1, 0);
        dp[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        ans=dp[1];
        dp=vector<int>(n + 1, 0);
        dp[n-2]=nums[n-2];
        for (int i = n - 3; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return max(dp[0],ans);
    }
};