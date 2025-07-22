class Solution {
public:
    int ans=0;
    vector<string>an;
    bool valid(int i, int j, int n) {
        return (i >= 0 && i < n) && (j >= 0 && j < n);
    }
    bool pos(int i,int j,int n){
        for(int k=0;k<i;k++){
            if(an[k][j]=='Q') return false;
        }
        for(int k=0;k<j;k++){
            if(an[i][k]=='Q') return false;
        }
        for(int k=0;k<n;k++){
            int x=i-k,y=j-k;
            if(valid(x,y,n)&&an[x][y]=='Q') return false;
            x=i-k;
            y=j+k;
            if(valid(x,y,n)&&an[x][y]=='Q') return false;
        }
        return true;
    }
    void help(int j,int n){
        if(j==n){
            ans++;
        }
        for(int i=0;i<n;i++){
            if(pos(j,i,n)) {
                an[j][i]='Q';
                help(j+1,n);
                an[j][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        string str;
        ans=0;
        for(int i=0;i<n;i++) str+='.';
        an=vector<string>(n,str);
        help(0,n);
        return ans;
    }
};