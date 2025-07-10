class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_multimap<int,int> m;
        int i=0;
        for(auto c: nums){
            m.insert({c,i});
            i++;
        }
        for(auto c:m){
            if(m.find(target-c.first)!=m.end() && (m.find(target-c.first))->second!=c.second){
                return {(m.find(target-c.first))->second,c.second};
            }
        }
        return{-1,-1};
    }
};