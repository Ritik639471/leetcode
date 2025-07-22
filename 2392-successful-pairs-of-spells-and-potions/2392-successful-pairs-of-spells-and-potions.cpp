class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size(),mid;
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int lo=0,hi=m-1;
            int a=0;
            while(lo<=hi){
                mid=lo+(hi-lo)/2;
                if((long long)spells[i]*(long long)potions[mid]>=success){
                    hi=mid-1;
                    a=m-mid;
                }else{
                    lo=mid+1;
                }
            }
            spells[i]=a;
        }
        return spells;
    }
};