class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& il, vector<int>& nil) {
        vector<vector<int>>ans;
        int n=il.size(),j=0,i;
        for(int i=0;i<n;i++){
            if(il[i][0]<=nil[0]){
                ans.push_back(il[i]);
                j++;
            }else break;
        }
        i=j;
        if(j==0){
            ans.push_back(nil);
        }
        else{
            if(ans[j-1][1]<nil[0]) {ans.push_back(nil);}
            else{ ans[j-1][1]=max(ans[j-1][1],nil[1]);j-=1;}
        }
        for(i;i<n;i++){
            if(ans[j][1]>=il[i][0]) ans[j][1]=max(ans[j][1],il[i][1]);
            else{
                ans.push_back(il[i]);
            }
        }
        return ans;
    }
};