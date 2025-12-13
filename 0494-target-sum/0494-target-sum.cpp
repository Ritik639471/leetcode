class Solution {
public:
    int findTargetSumWays(vector<int>& A, int d) {
    int n=A.size();
      int k=accumulate(A.begin(),A.end(),0);
    if(k-d<0||(k-d)%2) return 0;
    k=(k-d)/2;
	vector<long long>dp(k+1,0);
    dp[0]=1;
    for(int j=0;j<n;j++)
     for(int i=k;i>=0;i--)
      if(dp[i]&&i+A[j]<=k){ dp[i+A[j]]=(dp[i+A[j]]+dp[i]);}
    return dp[k];
    }
};