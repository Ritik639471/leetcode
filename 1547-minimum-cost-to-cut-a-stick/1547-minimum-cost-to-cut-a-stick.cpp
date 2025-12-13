class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int s=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(s,vector<int>(s,INT_MAX));
        for(int l=1;l<=s;l++){
            for(int i=0;i<=s-l;i++){
                int j=i+l-1;
                for(int k=i;k<=j;k++){
                    int a=0;
                    if(i==0&&j==s-1) a=n;
                    else if(i==0) a=cuts[j+1];
                    else if(j==s-1) a=n-cuts[i-1];
                    else a=cuts[j+1]-cuts[i-1];
                    if(i<k) a+=dp[i][k-1];
                    if(j>k) a+=dp[k+1][j];
                    dp[i][j]=min(dp[i][j],a);
                }
            }
        }
        return dp[0][s-1];
    }
};