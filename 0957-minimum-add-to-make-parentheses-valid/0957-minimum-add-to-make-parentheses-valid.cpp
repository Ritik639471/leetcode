class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0,b=0;
        for(auto c: s){
            if(c=='('){
                b++;
            }else{
                if(b>0) b--;
                else ans++;
            }
        }
        return ans+b;
    }
};