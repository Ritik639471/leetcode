class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        sort(nums.begin(),nums.end());
        vector<unordered_set<int>>s(n);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        s[0].insert(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<sum/2)s[i].insert(nums[i]);
            if(nums[i]==sum/2) return true;
            for(auto c: s[i-1]){
                if(c+nums[i]<sum/2)s[i].insert(c+nums[i]);
                if(c+nums[i]==sum/2) return true;
            }
            for(auto c: s[i-1]){
                if(c<sum/2) s[i].insert(c);
            }
        }
        return false;
    }
};