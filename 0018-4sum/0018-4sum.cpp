class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])continue;
            for (int l = i + 1; l < n; l++) {
                if (l > i+1 && nums[l] == nums[l - 1]) continue;
                int j = l + 1, k = n - 1;
                while (j < k) {
                    long sum = (long)nums[i]+(long)nums[l]+(long)nums[j]+(long)nums[k];
                    if (sum >(long)target)
                        k--;
                    else if (sum<(long)target)
                        j++;
                    else {
                        vector<int> v = {nums[i],nums[l],nums[j], nums[k]};
                        ans.push_back(v);
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1])
                            j++;
                        while (j < k && nums[k] == nums[k + 1])
                            k--;
                    }
                }
            }
        }
        return ans;
    }
};