class Solution {
public:
    void help(vector<vector<int>>&ans,int k,int n,vector<int>&a,int i){
        if(k<0||n<0) return;
        if(k==0&&n==0) {
            ans.push_back(a);
            return;
        }
        else if(k==0||n==0) return;
        for(int j=i;j<=9;j++){
            vector<int> b=a;
            b.push_back(j);
            help(ans,k-1,n-j,b,j+1);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>a;
        help(ans,k,n,a,1);
        return ans;
    }
};