class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int mx) {
        vector<string>ans;
        string st(mx,' ');
        int n=words.size(),i=0,l=0,c;
        while(i<n){
            int j=i,a=-1,b;
            l=0;
            while(j<n&&words[j].length()+1+a<=mx){
                a+=words[j].length()+1;
                j++;
            }
            b=j-i;
            if(b!=1) b--;
            c=(mx-a);
            while(i<j){
                for(int k=0;k<words[i].length();k++){
                    st[l++]=words[i][k];
                }
                if(l<mx) st[l++]=' ';
                i++;
                for(int k=0;k<(c/b)+(c%b!=0);k++){
                    if(l<mx) st[l++]=' ';
                    else break;
                }
                if(c%b!=0) c--;
            }
            ans.push_back(st);
        }
        l=0;
        i=0;
        c=ans.size()-1;
        while(i<mx){
            if(ans[c][i]==' '){
                while(i<mx-1&&ans[c][i+1]==' '){
                    i++;
                }
            }
            ans[c][l]=ans[c][i];
            l++;
            i++;
        }
        while(l<mx){
            ans[c][l++]=' ';
        }
        return ans;
    }
};