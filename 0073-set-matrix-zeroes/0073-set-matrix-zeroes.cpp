class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int M=matrix.size();
        int n=matrix[0].size();
        map<int,bool>mc,mr;
        for(int i=0;i<M;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    mc[i]=true;
                    mr[j]=true;
                }
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<n;j++){
                if(mc[i]||mr[j]) matrix[i][j]=0;
            }
        }
    }
};