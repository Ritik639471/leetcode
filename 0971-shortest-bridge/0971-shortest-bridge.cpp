class Solution {
public:
    bool valid(int i, int j, int n) {
        return (i >= 0 && i < n) && (j >= 0 && j < n);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        queue<pair<int, pair<int, int>>> q1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 2;
                }
                while (!q.empty()) {
                    auto c = q.front();
                    q.pop();
                    int a = 0;
                    for (int k = 0; k < 4; k++) {
                        int x = c.first + dir[k][0], y = c.second + dir[k][1];
                        if (valid(x, y, n) && grid[x][y] == 1) {
                            // cout<<x<<" "<<y<<endl;
                            q.push({x, y});
                            grid[x][y] = 2;
                        }
                        if (valid(x, y, n) && grid[x][y] == 0) {
                            a++;
                        }
                    }
                    if (a > 0)
                            q1.push({0,c});
                }
                while (!q1.empty()) {
                    auto c = q1.front();
                    q1.pop();
                    for (int k = 0; k < 4; k++) {
                        int x = c.second.first + dir[k][0],
                            y = c.second.second + dir[k][1];
                        if (valid(x, y, n) && grid[x][y] == 0) {
                            q1.push({c.first + 1, {x, y}});
                            grid[x][y] = 3;
                        }
                        if (valid(x, y, n) && grid[x][y] == 1) {
                            return c.first;
                        }
                    }
                }
            }
        }
        return 0;
    }
};