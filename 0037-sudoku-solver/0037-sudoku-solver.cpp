class Solution {
public:
    bool f=false;
    bool ok(vector<vector<char>>& board, int i, int j, int l) {
        for (int k = 0; k < 9; k++) {
            if ((board[i][k] - '0' == l) || (board[k][j] - '0' == l))
                return false;
        }
        int x = 3 * (i / 3), y = 3 * (j / 3);
        for (int ci = 0; ci < 3; ci++) {
            for (int cj = 0; cj < 3; cj++) {
                if (board[ci + x][cj + y] - '0' == l)
                    return false;
            }
        }
        return true;
    }
    void help(vector<vector<char>>& board, int i,int j) {
        if(i==9||f){f=true; return;}
        if(j==9){
            help(board,i+1,0);
            return;
        }
        if(board[i][j]=='.'){
            for(int l=1;l<=9;l++){
                if(f) continue;
                if(ok(board,i,j,l)){
                    board[i][j]=l+'0';
                    help(board,i,j+1);
                    if(f) continue;
                    board[i][j]='.';
                }
            }
        }else {
            help(board,i,j+1);
        }
    }
    void solveSudoku(vector<vector<char>>& board) { help(board,0,0);}
};