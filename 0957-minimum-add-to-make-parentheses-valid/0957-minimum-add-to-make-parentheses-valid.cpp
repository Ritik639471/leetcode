class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0,b=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                b++;
            }else{
                if(b>0) b--;
                else ans++;
            }
        }
        return ans+b;
    }
};