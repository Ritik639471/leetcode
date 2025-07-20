class Solution {
public:
    vector<vector<int>>g;
    bool f=false;
    int l=1,n,m;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool is(int i,int j) {return (i>=0&&i<m&&j>=0&&j<n);}
    void help(pair<int,int>cu,pair<int,int>pr,vector<vector<char>>& grid){
        g[cu.first][cu.second]=l;
        for(int i=0;i<4;i++){
            int x=cu.first+dir[i][0],y=cu.second+dir[i][1];
            if(is(x,y)&&(g[x][y]==0)&&(grid[x][y]==grid[cu.first][cu.second])){
                help({x,y},{cu.first,cu.second},grid);
            }
            else if(is(x,y)&&(g[x][y]==l)&&(grid[x][y]==grid[cu.first][cu.second])&&(x!=pr.first&&y!=pr.second)){
                f=true;
            }
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        g=vector<vector<int>>(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!g[i][j]){
                    g[i][j]=l;
                    help({i,j},{-1,-1},grid);
                    l++;
                    if(f) return f;
                }
            }
        }
        return f;
    }
};