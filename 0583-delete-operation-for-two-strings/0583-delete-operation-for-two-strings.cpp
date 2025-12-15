class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<int>dp(m+1,0),dp1;
        for(int i=n;i>=0;i--){
            dp1=dp;
            for(int j=m;j>=0;j--){
                if(j==m) dp[j]=n-i;
                else if(i==n) dp[j]=m-j;
                else if(word1[i]==word2[j]){
                    dp[j]=dp1[j+1];
                    dp[j]=min({1+dp[j+1],dp[j],1+dp1[j]});
                }else dp[j]=min({1+dp[j+1],1+dp1[j]});
            }
        }
        return dp[0];
    }
};