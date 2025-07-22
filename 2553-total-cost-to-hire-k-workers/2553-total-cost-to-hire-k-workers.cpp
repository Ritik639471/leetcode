class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        int n=costs.size();
        int lo=0,hi=n-1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p1,p2;
        for(int i=0;i<c;i++){
            if(lo>hi) break;
            if(lo==hi){
                p1.push({costs[lo],lo});
                lo++;
                break;
            }
            p1.push({costs[lo],lo});
            p2.push({costs[hi],hi});
            hi--;
            lo++;
        }
        int a,b;
        long long ans=0;
        for(int i=1;i<=k;i++){
            a=p1.size();
            b=p2.size();
            if(a==0){
                ans+=p2.top().first;
                p2.pop();
                b--;
            }else if(b==0){
                ans+=p1.top().first;
                p1.pop();
                a--;
            }else{
                if(p2.top().first>=p1.top().first){
                    ans+=p1.top().first;
                    p1.pop();
                    a--;
                }else{
                    ans+=p2.top().first;
                    p2.pop();
                    b--;
                }
            }
            if(a<c&&lo<=hi){
                p1.push({costs[lo],lo});
                lo++;
                a++;
            }
            if(b<c&&lo<=hi){
                p2.push({costs[hi],hi});
                hi--;
                b++;
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};