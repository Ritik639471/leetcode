class Solution {
public:
    int n1,n2,ans=INT_MAX;
    bool f;
    void help(string& a, string& b,int i){
        int c=(i!=0);
        for(int j=0;j<n2;j++){
            if(a[(i+j)%n1]!=b[j]) return;
            if((i+j)%n1==0) c++;
        }
        ans=min(ans,c);
        f=true;
    }
    int repeatedStringMatch(string a, string b) {
        n1=a.length();n2=b.length();
        for(int i=0;i<n1;i++){
            if(a[i]==b[0]) help(a,b,i);
        }
        return f?ans:-1;
    }
};