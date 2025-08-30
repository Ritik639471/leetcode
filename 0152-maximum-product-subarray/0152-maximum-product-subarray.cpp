class Solution {
public:
     
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxv=INT_MIN,nu=0;
        // vector<vector<int>>dp(n,vector<int>(n,1));
        for(int i=0;i<n;i++){
            nu=nums[i];
            maxv=max(maxv,nu);
            for(int j=i+1;j<n;j++){
                nu=nu*nums[j];
                maxv=max(maxv,nu);
                if(nu==0) break;
            }
        }
        return maxv;
    }
};