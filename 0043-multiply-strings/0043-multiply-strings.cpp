class Solution {
public:
    string add(string num1, string num2){
        string ans;
        int k=0;
        int i=num1.size()-1,j=num2.size()-1;
        while(i>=0&&j>=0){
            k+=num1[i--]+num2[j--]-'0'-'0';
            ans=to_string(k%10)+ans;
            k/=10;
        }
        while(i>=0){
            k+=num1[i--]-'0';
            ans=to_string(k%10)+ans;
            k/=10;
        }
        while(j>=0){
            k+=num2[j--]-'0';
            ans=to_string(k%10)+ans;
            k/=10;
        }
        while(k>0){
            ans=to_string(k%10)+ans;
            k/=10;
        }
        return ans;
    }
    string md(string s,int i){
        if(i==0) return "0";
        int k=0;
        for(int j=s.size()-1;j>=0;j--){
            k+=(s[j]-'0')*i;
            s[j]='0'+k%10;
            k/=10;
        }
        while(k>0){
            s=to_string(k%10)+s;
            k/=10;
        }
        return s;
    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        if(num1=="1") return num2;
        if(num2=="1") return num1;
        string ans="0",s="";

        for(int i=num2.size()-1;i>=0;i--){
            ans=add(ans,md(num1+s,num2[i]-'0'));
            s+="0";
        }
        return ans;
    }
};