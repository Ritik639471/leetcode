class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = 0, mx = 0,ns=nums.size();
        for (int i = 0; i < ns - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                n++;
            } else {
                mx = max(mx,n + 1);
                n = 0;
            }
        }
        return max(mx,n+1);
    }
};