class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp;
        int n=nums.size();
        int a=0,ans=0,prev;
        for(int i=0;i<n;i++){
            mp.insert(nums[i]);
        }
        for(auto c:mp){
            if(mp.find(c-1)==mp.end()){
                prev=c;
                a=1;
                while(mp.find(prev+1)!=mp.end()){
                    prev++;
                    a++;
                }
                ans=max(a,ans);
            }
        }
        return ans;
    }
};