class Solution {
public:
    void help(vector<string>& ans,string s,int a,int b,int c,int n,string st){
        if(c>3||b>255) return ;
        if(a==n){
            if(c<3) return;
            if(b>=0&&b<256){
                ans.push_back(st);
                return;
            }
        }
        if(b==-1){
            help(ans,s,a+1,s[a]-'0',c,n,st+s[a]);
        }else{
            if(b!=0) help(ans,s,a+1,b*10+(s[a]-'0'),c,n,st+s[a]);
            st+='.';
            help(ans,s,a+1,s[a]-'0',c+1,n,st+s[a]);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.length();
        if(n>12) return {};
        vector<string>ans;
        help(ans,s,0,-1,0,n,"");
        return ans;
    }
};