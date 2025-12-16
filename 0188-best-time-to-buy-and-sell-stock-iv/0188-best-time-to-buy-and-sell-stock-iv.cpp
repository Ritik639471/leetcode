class Solution {
public:
    int maxProfit(int k, vector<int>& A) {
        // int n = A.size();
        // vector<int> dp(n + 1, 0),dp1;
        // for (int l = 1; l <= 2*k; l++) {
        //     int prev=0;
        //     for (int i = n - 1; i >= 0; i--) {
        //         int cur=dp[i];
        //         if(l%2==0){
        //             dp[i]=max(dp[i+1],-A[i]+prev);
        //         }
        //         else{
        //             dp[i]=max(dp[i+1],A[i]+prev);
        //         }
        //         prev=cur;
        //         cout<<dp[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        // return dp[0];
        int n = A.size();
        vector<int> dp(2*k + 1, 0);
        for (int i = n-1;i>=0;i--) {
            for (int l = 1;l<=2*k;l++) {
                if(l%2==0){
                    dp[l]=max(dp[l],-A[i]+dp[l-1]);
                }
                else{
                    dp[l]=max(dp[l],A[i]+dp[l-1]);
                }
            }
        }
        return dp[2*k];
    }
};