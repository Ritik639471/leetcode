class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        vector<int>dp((sum/2)+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=sum/2;j>=0;j--){
                if(dp[j]&&nums[i]+j<=sum/2) dp[nums[i]+j]=true;
            }
        }
        return dp[sum/2];
    }
};