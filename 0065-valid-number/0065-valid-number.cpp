class Solution {
public:
    bool isNumber(string s) {
        int n=s.length(),i=0;
        if(s[0]=='+'||s[0]=='-') i++;
        int a=0;
        if(i==n||s[i]=='e'||s[i]=='E') return false;
        while(i<n&&s[i]!='e'&&s[i]!='E'){
            if(s[i]>='a'&&s[i]<='z'||s[i]<='Z'&&s[i]>='A') return false;
            if(s[i]=='.') {
                a++;
                if(a==2||(i==0||!(s[i-1]>='0'&&s[i-1]<='9'))&&(i==n-1||!(s[i+1]>='0'&&s[i+1]<='9'))){cout<<"1"; return false;}
            }
            if(s[i]=='+'||s[i]=='-') return false;
            i++;
        }
        if(i<n&&s[i]=='e'||s[i]=='E') {
            i++;
            if(i==n) return false;
        }
        if(i<n){
            if(s[i]=='+'||s[i]=='-') i++;
            if(i==n) return false;
            while(i<n){
              if(s[i]<'0'||s[i]>'9') return false;
              i++;
            }
        }
        return true;
    }
};