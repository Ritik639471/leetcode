class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=0,a=0;
        vector<int>dp(n);
        vector<int>dp1(n,1);
        for(int i=n-1;i>=0;i--){
            dp[i]=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    if(dp[i]<1+dp[j]) {
                        dp[i]=1+dp[j];
                        dp1[i]=dp1[j];
                    }else if(dp[i]==1+dp[j]) dp1[i]+=dp1[j];
                }
            }
            ans=max(ans,dp[i]);
        }
        for(int i=0;i<n;i++){ if(dp[i]==ans) a+=dp1[i];}
        return a;
    }
};