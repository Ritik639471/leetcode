class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool>mp;
        int n=nums.size();
        if(n==0) return 0;
        int a=1,ans=1;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==prev) continue;
            if(nums[i]==prev+1){
                a+=1;
                prev++;
            }else{
                ans=max(ans,a);
                a=1;
                prev=nums[i];
            }
        }
        ans=max(ans,a);
        return ans;
    }
};