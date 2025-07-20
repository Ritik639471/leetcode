class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int m=maze.size(),n=maze[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{e[0],e[1]},1});
        maze[e[0]][e[1]]='+';
        pair<pair<int,int>,int> c;
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            c=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=c.first.first+dir[i][0],y=c.first.second+dir[i][1];
                if(x>=0&&x<m&&y>=0&&y<n&&maze[x][y]=='.'){
                    if(x==0||y==0||x==m-1||y==n-1){
                        return c.second;
                    }
                    q.push({{x,y},c.second+1});
                    maze[x][y]='+';
                }
            }
        }
        return -1;
    }
};