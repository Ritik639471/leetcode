class Solution {
public:
    int m=1e9+7;
    int numberOfWays(int n, int x) {
        vector<long long>a(n+1,0);
        a[0]=1;
        long long ans=0;
        for(long i=n;i>=1;i--){
            long long l=pow(i,x);
            for(int j=n-1;j>=0;j--){
                if(a[j]&&(j+l)<=n){
                    a[j+l]+=(a[j]);
                }
            }
        }
        return a[n]%m;
    }
};