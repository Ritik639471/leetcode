class Solution {
public:
    int help(int r, int c,int i, int j1,int j2,vector<vector<vector<int>>>&dp,vector<vector<int>> &grid){
    if(i==r-1){
        if(j1<c&&j1>-1&&j2<c&&j2>-1){
            if(j1==j2) return dp[i][j1][j2]=grid[i][j1];
            else return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
        } else return 0;
    }
    if(j1>=c || j1<0 || j2>=c || j2<0){
        return 0;
    }
    if(dp[i][j1][j2]>0) return dp[i][j1][j2];
    int a=0;
    int dir[9][2]={{0,0},{0,1},{1,0},{1,1},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
    for(int l=0;l<9;l++){
        if(j1+dir[l][0]>=c || j1+dir[l][0]<0 || j2+dir[l][1]>=c || j2+dir[l][1]<0) continue;
        if (dp[i+1][j1+dir[l][0]][j2+dir[l][1]]<0) dp[i+1][j1+dir[l][0]][j2+dir[l][1]]=help(r,c,i+1,j1+dir[l][0],j2+dir[l][1],dp,grid);
        a=max(a,dp[i+1][j1+dir[l][0]][j2+dir[l][1]]);
    }
    if(j1!=j2) return dp[i][j1][j2]=a+grid[i][j1]+grid[i][j2];
    else return dp[i][j1][j2]=a+grid[i][j1];
    
}
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return help(r,c,0,0,c-1,dp,grid);
    }
};