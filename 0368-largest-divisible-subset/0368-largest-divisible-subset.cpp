class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        int maxi=1;
        int li=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                li=i;
            }
        }
        vector<int>temp(maxi);
        maxi--;
        temp[maxi--]=nums[li];
        while(hash[li]!=li){
            li=hash[li];
            temp[maxi--]=nums[li];
        }
        return temp;
    }
};