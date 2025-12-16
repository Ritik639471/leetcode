class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        vector<int>dp(n+1,0),dp1(n+1,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=max({-arr[i]+dp1[i+1],dp[i+1]});
            dp1[i]=max({arr[i]+dp[i+1],dp1[i+1]});
        }
        return dp[0];
    }
};