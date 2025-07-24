class Solution {
public:
    vector<vector<string>> ans;
    void help(string& s,int i,int n,vector<string>v){
        if(i==n){
            ans.push_back(v);
        }
        for(int j=i;j<n;j++){
            int k=j,l=i;
            bool f=true;
            while(l<=k){
                if(s[l]!=s[k]){
                    f=false;
                    break;
                }
                l++;
                k--;
            }
            if(f){v.push_back(s.substr(i,j-i+1)); help(s,j+1,n,v);v.pop_back();}
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        help(s,0,n,{});
        return ans;
    }
};