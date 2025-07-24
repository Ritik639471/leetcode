class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool>mp;
        int n=nums.size();
        if(n==0) return 0;
        int a=1,ans=1,prev=INT_MAX;
        for(int i=0;i<n;i++){
            prev=min(prev,nums[i]);
            mp[nums[i]]=true;
        }
        for(auto c:mp){
            if(prev==c.first) continue;
            if(prev+1==c.first) a++;
            else a=1;
            prev=c.first;
            ans=max(a,ans);
        }
        return ans;
    }
};