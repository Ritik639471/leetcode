class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0,j=0;
        char prev='#';
        while(i<n){
            if(prev=='#'&&s[i]!=' '){
                s[j]=s[i];
                prev=s[i];
                j++;
            }else if(prev==' '&&s[i]!=' '){
                s[j]=' ';
                j+=1;
                s[j]=s[i];
                prev=s[i];
                j++;
            }else if(prev!='#'&&s[i]==' '){
                prev=' ';
            }else if(prev!=' '&&s[i]!=' '){
                s[j++]=s[i];
            }
            i++;
        }
        n=j;
        i=0;j=n-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        i=0;
        while(i<n){
            j=i;
            while(j<n&&s[j]!=' ') j++;
            int k=j-1;
            while(i<=k){
                swap(s[i],s[k]);
                i++;
                k--;
            }
            i=j+1;
        }
        return s.substr(0,n);
    }
};