class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> great(n,-1);
        vector<int> less(n,-1);
        int min=prices[0],max=prices[n-1];
        for(int i=0;i<n;i++){
           if(prices[i]<min){ min=prices[i];}
           if(prices[n-i-1]>max){ max=prices[n-1-i];}
           great[n-1-i]=max;
           less[i]=min;
        }
        max=0;
        for(int i=0;i<n;i++){
            great[i]-=less[i];
            if(great[i]>max) max=great[i];
        }
        return max;
    }
};