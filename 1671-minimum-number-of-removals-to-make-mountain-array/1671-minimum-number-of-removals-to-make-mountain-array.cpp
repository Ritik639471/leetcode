class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int>dp(n,1),dp1(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[i]) dp[i]=max(dp[i],1+dp[j]);
            }
            // cout<<dp[i]<<" ";
        }
        // cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) dp1[i]=max(dp1[i],1+dp1[j]);
            }
            // cout<<dp1[i]<<" ";
        }
        // cout<<endl;
        for(int i=0;i<n;i++){
            if(dp[i]!=1&&dp1[i]!=1) ans=max(ans,dp[i]+dp1[i]-1);
        }
        return n-ans;
    }
};