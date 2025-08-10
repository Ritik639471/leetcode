class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>ed(n+1);
        for(int i=0;i<flights.size();i++){
            ed[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        int ans=INT_MAX;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        q.push({0,src,0});
        vector<vector<int>> minCost(n, vector<int>(k + 2, INT_MAX));
        minCost[src][0] = 0;
        while(!q.empty()){
            auto c=q.top();
            q.pop();
            if(get<1>(c)==dst){
                ans=get<0>(c);
                break;
            }
            if(get<2>(c)>k) continue;
            for(auto b: ed[get<1>(c)]){
                if (get<0>(c)+b.second<minCost[b.first][get<2>(c)+1]) {
                    minCost[b.first][get<2>(c)+1]=get<0>(c)+b.second;
                    q.push({get<0>(c)+b.second,b.first,get<2>(c)+1});
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};