class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        dp=vector<vector<int>>(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<n1;i++){
            dp[i][n2]=n1-i;
        }
        for(int i=0;i<n2;i++){
            dp[n1][i]=n2-i;
        }
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                dp[i][j]=min({(word1[i]!=word2[j])+dp[i+1][j+1],1+dp[i+1][j],1+dp[i][j+1]});
            }
        }
        return dp[0][0];
    }
};