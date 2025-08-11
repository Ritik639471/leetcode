class Solution {
public:
    int help(string &s,int i,int n,vector<int>&dp,vector<vector<bool>>& isPal){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=n-i-1,j=i;
        while(j<n){
            if(isPal[i][j]){
                ans = min(ans, (j == n - 1 ? 0 : 1 + help(s, j + 1, n, dp,isPal)));
            }
            j++;
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPal[i+1][j-1])) {
                    isPal[i][j] = true;
                }
            }
        }
        return help(s,0,n,dp,isPal);
    }
};
