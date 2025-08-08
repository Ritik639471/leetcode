class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(),ans=0;
        map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[fruits[j]]++;
            int k=j;
            while(k<n-1&&fruits[k+1]==fruits[j]){
                k++;
                mp[fruits[j]]++;
            }
            j=k;
            if(mp.size()>2){
                while(i<=j){
                    mp[fruits[i]]-=1;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]);
                        i++;
                        break;
                    }
                    i++;
                }
            }
            int a=0;
            for(auto c: mp){
                a+=c.second;
            }
            ans=max(a,ans);
            j++;
        }
        return ans;
    }
};