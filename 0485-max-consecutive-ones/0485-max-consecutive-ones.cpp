class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0,n=0;
        for(int i=0;i<nums.size();i++){
            if (nums[i] == 1) {
                n++;
            } else {
                if (max < n) {
                    max = n;
                    n = 0;
                } else
                    n = 0;
            }
        }
        if (max < n)
            return n;
        return max;
    }
};