class Solution {
public:
    bool compare(string s,string t){
        int n=s.size(),m=t.size();
        if(n+1!=m) return false;
        int a=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i+a]) a++;
            if(a==2||s[i]!=t[i+a]) return false;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
        int mx=1;
        sort(words.begin(),words.end(),[](string a,string b){
            return a.size()>b.size();
        });
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j])&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};