class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int dp[302][302] = {0};
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int cost=0;
                for(int k=i;k<=j;k++){
                    cost=max(cost,nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=cost;
            }
        }
        return dp[1][n];
    }
};