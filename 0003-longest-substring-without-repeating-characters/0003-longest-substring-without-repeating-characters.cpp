class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map <char,int> m;
        int start=0,max=0,count=0;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                int j=start;
                while(s[j]!=s[i]){
                    m.erase(s[j]);
                    count--;
                    start++;
                    j++;
                }
                m.erase(s[i]);
                start++;
                count--;
            }
            m.insert({s[i],i});
            count++;
            if(max<count) max=count;
        }
        return max;
    }
};