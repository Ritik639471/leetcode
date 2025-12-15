class Solution {
public:
    int maxProfit(vector<int>& A) {
        int k=2;
        int n = A.size();
        vector<int> dp(n + 1, 0),dp1;
        for (int l = 1; l <= 2*k; l++) {
            int prev=0;
            for (int i = n - 1; i >= 0; i--) {
                int cur=dp[i];
                if(l%2==0){
                    dp[i]=max(dp[i+1],-A[i]+prev);
                }
                else{
                    dp[i]=max(dp[i+1],A[i]+prev);
                }
                prev=cur;
            }
        }
        return dp[0];
    }
};