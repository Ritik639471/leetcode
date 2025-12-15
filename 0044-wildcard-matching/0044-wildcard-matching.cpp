class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<bool>dp(m+1,false),dp1;
        dp[m]=true;
        for(int j=m-1;j>=0;j--){
            if(p[j]=='*') dp[j]=dp[j+1];
        }
        for(int i=n-1;i>=0;i--){
            dp1=dp;
            bool prev=(i==n-1);
            dp[m]=false;
            for(int j=m-1;j>=0;j--){
                bool cur=dp[j];
                dp[j]=false;
                if(s[i]==p[j]||p[j]=='?') dp[j]=prev;
                else if(p[j]=='*') dp[j]=prev|cur|dp[j+1];
                prev=cur;
            }
        }
        return dp[0];	
    }
};