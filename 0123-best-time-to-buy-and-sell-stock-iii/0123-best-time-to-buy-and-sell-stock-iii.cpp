class Solution {
public:
    int maxProfit(vector<int>& A) {
        int k=2;
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