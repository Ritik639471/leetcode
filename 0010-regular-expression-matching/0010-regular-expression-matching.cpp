class Solution {
private:
    vector<vector<int>>dp;
public:
    int help(string s, string p,int i,int j){
        if(i<0&&j<0){
            return 1;
        }
        if(i>=0&&j<0) return 0;
        if(i<0&&j>=0){
            if(p[j]=='.'||p[j]!='*') return 0;
            while(j>0&&p[j]=='*'){
                j-=2;
            }
            if(j<0) return 1;
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j]) dp[i][j]=max(dp[i][j],help(s,p,i-1,j-1));
        else if(p[j]=='.') dp[i][j]=max(dp[i][j],help(s,p,i-1,j-1));
        else if(p[j]=='*'){
            dp[i][j]=max(dp[i][j],help(s,p,i,j-2));
            int k=i;
            while(k>=0&&(s[k]==p[j-1]||p[j-1]=='.')){
                dp[i][j]=max(dp[i][j],help(s,p,k-1,j-2));
                k--;
            }
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int n1=s.length(),n2=p.length();
        dp=vector<vector<int>>(n1,vector<int>(n2,-1));
        dp[n1-1][n2-1]=help(s,p,n1-1,n2-1);
        return dp[n1-1][n2-1]==1;
    }
};