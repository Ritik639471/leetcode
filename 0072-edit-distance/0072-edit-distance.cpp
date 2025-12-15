class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<int>dp(m+1,0),dp1;
        for(int j=m-1;j>=0;j--){
            dp[j]=m-j;
        }
        for(int i=n-1;i>=0;i--){
            dp1=dp;
            for(int j=m;j>=0;j--){
                if(j==m) dp[j]=n-i;
                else dp[j]=min({1+dp[j+1],1+dp1[j],(s1[i]!=s2[j])+dp1[j+1]});
            }
        }
        return dp[0];
    }
};