class Solution {
public:
    vector<vector<int>>dp;
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length(),n2=text2.length();
        dp=vector<vector<int>>(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<n1;i++){
            dp[i][n2]=0;
        }
        for(int i=0;i<n2;i++){
            dp[n1][i]=0;
        }
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                dp[i][j]=max({(text1[i]==text2[j])+dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
            }
        }
        return dp[0][0];
    }
};