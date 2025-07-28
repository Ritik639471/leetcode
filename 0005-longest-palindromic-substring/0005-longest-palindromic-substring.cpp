class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 1, n = s.length();
        string a;
        a+=s[0];
        for (int i = 0; i < n; i++) {
            int lo = i, hi = i;
            while (lo > 0 && hi < n - 1 && s[lo - 1] == s[hi + 1]) {
                lo--;
                hi++;
            }
            if (ans < hi - lo + 1) {
                ans = hi - lo + 1;
                a = s.substr(lo, ans);
            }
            if (i < n - 1 && s[i] == s[i + 1]) {
                lo = i;
                hi = i + 1;
                while (lo > 0 && hi < n - 1 && s[lo - 1] == s[hi + 1]) {
                    lo--;
                    hi++;
                }
                if (ans < hi - lo + 1) {
                    ans = hi - lo + 1;
                    a = s.substr(lo, ans);
                }
            }
        }
        return a;
    }
};