class Solution {
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool valid(int i ,int j ,int n ,int m){
     return i>=0&&i<n&&j>=0&&j<m;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size();
        if(image[sr][sc]==color) return image;
        int a=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            auto c=q.front();
            q.pop();
            if(image[c.first][c.second]==color) continue;
            image[c.first][c.second]=color;
            for(int l=0;l<4;l++){
                int x=dir[l][0]+c.first,y=dir[l][1]+c.second;
                if((x>=0&&x<m&&y>=0&&y<n)&&image[x][y]==a){
                    q.push({x,y});
                }
            }
        }
        return image;
    }
};