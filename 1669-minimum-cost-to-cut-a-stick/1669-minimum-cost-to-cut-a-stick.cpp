class Solution {
public:
    void help(vector<int>& cuts,int i,int j,vector<vector<int>>&dp,int n1,int n2){
        if(i>j) return;
        if(i==j) {
            dp[i][j]=n2-n1;
            return;
        }
        if(dp[i][j]!=INT_MAX) return;
        help(cuts,i+1,j,dp,cuts[i],n2);
        dp[i][j]=min(dp[i][j],n2-n1+dp[i+1][j]);
        help(cuts,i,j-1,dp,n1,cuts[j]);
        dp[i][j]=min(dp[i][j],n2-n1+dp[i][j-1]);
        for(int l=i+1;l<j;l++){
            help(cuts,i,l-1,dp,n1,cuts[l]);
            help(cuts,l+1,j,dp,cuts[l],n2);
            dp[i][j]=min(dp[i][j],n2-n1+dp[i][l-1]+dp[l+1][j]);
        }
    }
    int minCost(int n, vector<int>& cuts) {
        int s=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(s,vector<int>(s,INT_MAX));
        help(cuts,0,s-1,dp,0,n);
        return dp[0][s-1];
    }
};