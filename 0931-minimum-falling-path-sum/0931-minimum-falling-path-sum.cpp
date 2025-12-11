class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int  n=matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int a=INT_MAX;
                if(j-1>=0) a=min(a,matrix[i-1][j-1]);
                a=min(a,matrix[i-1][j]);
                if(j+1<n) a=min(a,matrix[i-1][j+1]);
                matrix[i][j]+=a;
            }
        }
        int a=INT_MAX;
        for(int i=0;i<n;i++){
            a=min(a,matrix[n-1][i]);
        }
        return a;
    }
};