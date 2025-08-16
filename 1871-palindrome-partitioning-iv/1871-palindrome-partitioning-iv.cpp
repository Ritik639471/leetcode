class Solution {
public:
    bool checkPartitioning(string s) {
        int n=s.length();
        vector<vector<bool>>dp(2,vector<bool>(n));
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPal[i+1][j-1])) {
                    isPal[i][j] = true;
                }
            }
        }
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n-1; i++) {
                int j = i + len - 1;
                if (isPal[i][j]&&isPal[j+1][n-1]) {
                    dp[0][i]=true;
                }
            }
        }
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n-2; i++) {
                int j = i + len - 1;
                if (isPal[i][j]&&dp[0][j+1]) {
                    dp[1][i]=true;
                }
            }
        }
        return dp[1][0];
    }
};