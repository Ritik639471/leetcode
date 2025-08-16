class Solution {
public:
    int palindromePartition(string s, int k) {
        int n=s.length();
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        vector<vector<int>> isPal(n, vector<int>(n,0));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                isPal[i][j]=isPal[i+1][j-1]+(s[i]!=s[j]);
            }
        }
        dp[0][n]=0;
        for(int l=1;l<=k;l++){
            for(int len=1;len<=n;len++){
                for(int i=0;i+len<=n;i++){
                    int j=i+len-1;
                    if(dp[l-1][j+1]!=-1) {
                        if(dp[l][i]==-1) dp[l][i]=isPal[i][j]+dp[l-1][j+1];
                        else dp[l][i]=min(dp[l][i],isPal[i][j]+dp[l-1][j+1]);
                    }
                }
            }
        }
        return dp[k][0];
    }
};