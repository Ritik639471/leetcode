class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        for(int i=1;i<n;i++) arr[i]=arr[i-1]^arr[i];
        vector<int>ans(queries.size());
        int i=0;
        for(auto c:queries){
            if(c[0]==0) ans[i++]=arr[c[1]];
            else ans[i++]=arr[c[1]]^arr[c[0]-1];
        }
        return ans;
    }
};