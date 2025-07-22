class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        int n=nums.size();
        q.push_back(0);
        for(int i=1;i<k;i++){
            while(!q.empty()&&nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int>ans(n-k+1);
        ans[0]=nums[q.front()];
        for(int i=k;i<n;i++){
            while(!q.empty()&&q.front()<=i-k) q.pop_front();
            while(!q.empty()&&nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            ans[i-k+1]=nums[q.front()];
        }
        return ans;
    }
};