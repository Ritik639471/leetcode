class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        int n=costs.size();
        int lo=0,hi=n-1;
        set<pair<int,int>>p1,p2;
        for(int i=0;i<c;i++){
            if(lo>hi) break;
            if(lo==hi){
                p1.insert({costs[lo],lo});
                lo++;
                break;
            }
            p1.insert({costs[lo],lo});
            p2.insert({costs[hi],hi});
            hi--;
            lo++;
        }
        int a=p1.size(),b=p2.size();
        long long ans=0;
        for(int i=1;i<=k;i++){
            if(a==0){
                ans+=p2.begin()->first;
                p2.erase(p2.begin());
                b--;
            }else if(b==0){
                ans+=p1.begin()->first;
                p1.erase(p1.begin());
                a--;
            }else{
                if(p2.begin()->first>=p1.begin()->first){
                    ans+=p1.begin()->first;
                    p1.erase(p1.begin());
                    a--;
                }else{
                    ans+=p2.begin()->first;
                    p2.erase(p2.begin());
                    b--;
                }
            }
            if(a<c&&lo<=hi){
                p1.insert({costs[lo],lo});
                lo++;
                a++;
            }
            if(b<c&&lo<=hi){
                p2.insert({costs[hi],hi});
                hi--;
                b++;
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};