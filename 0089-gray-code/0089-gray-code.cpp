class Solution {
public:
    void help(vector<int>&ans,int a,int b,int n){
        if(n==0){
            ans.push_back(a);
            return;
        }
        if(b%2==0){
            help(ans,a*2+0,b,n-1);
            help(ans,a*2+1,b+1,n-1);
        }else{
            help(ans,a*2+1,b+1,n-1);
            help(ans,a*2+0,b,n-1);
        }
    }
    vector<int> grayCode(int n) {
        vector<int>ans;
        help(ans,0,0,n);
        return ans;
    }
};