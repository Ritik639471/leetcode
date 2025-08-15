class Solution {
public:
    int m=1e9+7;
    int numberOfWays(int n, int x) {
        vector<long long>a(n+1,0);
        a[0]=1;
        long long ans=0;
        for(long i=n;i>=1;i--){
            for(int j=n-1;j>=0;j--){
                if(a[j]&&(j+pow(i,x))<=n){
                    a[j+pow(i,x)]+=(a[j]);
                }
            }
        }
        return a[n]%m;
    }
};