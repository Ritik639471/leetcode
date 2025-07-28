class Solution {
private:
    bool f=false;
public:
    void help(string s, string p,int i,int j){
        if(i<0&&j<0){
            f=true;
            return;
        }
        if(i>=0&&j<0) return;
        if(i<0&&j>=0){
            if(p[j]=='.'||p[j]!='*') return;
            help(s,p,i,j-2);
            return;
        }
        if(s[i]==p[j]) help(s,p,i-1,j-1);
        else if(p[j]=='.') help(s,p,i-1,j-1);
        else if(p[j]=='*'){
            help(s,p,i,j-2);
            while(i>=0&&(s[i]==p[j-1]||p[j-1]=='.')){
                help(s,p,i-1,j-2);
                i--;
            }
        }
    }
    bool isMatch(string s, string p) {
        int n1=s.length(),n2=p.length();
        help(s,p,n1-1,n2-1);
        return f;
    }
};