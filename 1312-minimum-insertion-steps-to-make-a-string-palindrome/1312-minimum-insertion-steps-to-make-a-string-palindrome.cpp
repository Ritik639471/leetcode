class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        vector<int>a(n+1,0),b,c;
        for(int l=1;l<=n;l++){
            c=b;
            b=a;
            for(int i=0;i+l<=n;i++){
                int j=i+l-1;
                if(i==j) a[i]=1;
                else if(s[i]==s[j]) a[i]=2+c[i+1];
                else a[i]=max(b[i],b[i+1]);
            }
        }
        return n-a[0];
    }
};