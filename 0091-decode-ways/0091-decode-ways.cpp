class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==1){
            return s[0]>='1'&&s[0]<='9';
        }else if(n==2){
            return (s[0]>='1'&&s[0]<='9'&&s[1]>='1'&&s[1]<='9')+(s[0]=='1'&&s[1]>='0'&&s[1]<='9'||s[0]=='2'&&s[1]>='0'&&s[1]<='6');
        }
        vector<int>dp(n,0);
        dp[n-1]=s[n-1]>='1'&&s[n-1]<='9';
        dp[n-2]=(s[n-2]>='1'&&s[n-2]<='9'&&dp[n-1])+(s[n-2]=='1'&&s[n-1]>='0'&&s[n-1]<='9'||s[n-2]=='2'&&s[n-1]>='0'&&s[n-1]<='6');
        for(int i=n-3;i>=0;i--){
            if(s[i]>='1'&&s[i]<='9') dp[i]+=dp[i+1];
            if(i<n-1&&s[i]=='1'&&s[i+1]>='0'&&s[i+1]<='9') dp[i]+=dp[i+2];
            if(i<n-1&&s[i]=='2'&&s[i+1]>='0'&&s[i+1]<='6') dp[i]+=dp[i+2];
        }
        return dp[0];
    }
};