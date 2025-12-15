class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<long long>dp(n+1,0),dp1;
        long long a=1e11;
        for(int i=m-1;i>=0;i--){
            dp1=dp;
            for(int j=n-1;j>=0;j--){
                dp[j]=dp[j+1];
                if(i==m-1&&s[j]==t[i]) dp[j]+=1;
                else if(s[j]==t[i]) dp[j]=(dp[j]+dp1[j+1])%a;
            }
        }
        return dp[0];
    }
};