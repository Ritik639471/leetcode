class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a!=0||b!=0||c!=0){
            if((a%2|b%2)!=c%2) {
                ans++;
                if(a%2&&b%2) ans++;
            }
            a/=2;
            b/=2;
            c/=2;
        }
        return ans;
    }
};