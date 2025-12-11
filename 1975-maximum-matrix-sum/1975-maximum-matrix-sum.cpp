class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long ans=0;
        int a=INT_MAX,b=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0) b++;
                a=min(a,abs(matrix[i][j]));
                ans+=abs(matrix[i][j]);
            }
        }
        if(b%2) ans-=2*a;
        return ans;
    }
};