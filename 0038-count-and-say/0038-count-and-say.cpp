class Solution {
public:
    string countAndSay(int n) {
        string st="1";
        for(int i=1;i<n;i++){
            string s;
            for(int j=0;j<st.length();j++){
                char c=st[j];
                int a=1;
                while(j<st.length()-1&&st[j+1]==c){
                    j++;
                    a++;
                }
                s+=('0'+a);
                s+=c;
            }
            st=s;
        }
        return st;
    }
};