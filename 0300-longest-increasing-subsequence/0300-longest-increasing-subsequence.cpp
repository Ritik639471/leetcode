class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
    int m=0;
    for(int i=0;i<n;i++){
        if(m==0||m>0&&a[m-1]<nums[i]) {a.push_back(nums[i]);m++;}
        else {
            auto it=lower_bound(a.begin(), a.end(),nums[i]);
            if (it != a.end()) {
               *it = nums[i];
            }
        }
    }
    return m;
    }
};