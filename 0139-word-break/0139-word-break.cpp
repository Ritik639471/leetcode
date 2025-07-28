class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool>dp(n+1);
        dp[n]=true;
        map<string,bool>mp;
        for(auto c: wordDict){
            mp[c]=true;
        }
        for(int i=n-1;i>=0;i--){
            string a="";
            for(int j=0;i+j<n&&j<20;j++){
                a+=s[i+j];
                if(mp[a]&&dp[i+j+1]) {dp[i]=true;break;}
            }
        }
        return dp[0];
    }
};