class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int sum=0,ans=0,s=0;
        s=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            if(abs(s-2*sum)%2==0) ans++;
        }
        return ans;
    }
};