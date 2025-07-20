class Solution {
public:
    vector<int> dp;
    int help(vector<int>& nums,int i,int n){
        if(i>=n) return dp[n]=0;
        if(dp[i]!=-1) return dp[i];
        if(i==n-1) return dp[n-1]=nums[n-1];
        if(dp[i+1]==-1) dp[i+1]=help(nums,i+1,n);
        if(dp[i+2]==-1) dp[i+2]=help(nums,i+2,n);
        return dp[i]=dp[i+1]>=(nums[i]+dp[i+2])?dp[i+1]:(nums[i]+dp[i+2]);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp=vector<int> (n+1,-1);
        dp[n]=help(nums,0,n);
        return dp[n];
    }
};