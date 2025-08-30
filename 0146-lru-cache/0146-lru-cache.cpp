class LRUCache {
public:
    deque<pair<int,int>>q;
    vector<int>a;
    vector<int>b;
    int n,m;
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);   
        a=vector<int>(10005,-1);
        b=vector<int>(10005,0);
        n=capacity;
        m=0;
    }
    
    int get(int key) {
        if(a[key]==-1||b[key]==0) return -1;
        q.push_front({key,b[key]+1});
        b[key]++;
        return a[key];
    }
    
    void put(int key, int value) {
        if(a[key]!=-1){
            q.push_front({key,b[key]+1});
            b[key]++;
            a[key]=value;
            return;
        }
        if(m==n){
            while(!q.empty()){
             if(a[q.back().first]==-1){
                q.pop_back();
              }else if(q.back().second!=b[q.back().first]){
                q.pop_back();
              }else{
                a[q.back().first]=-1;
                m-=1;
                break;
              } 
            }
        }
        m++;
        q.push_front({key,b[key]+1});
        b[key]++;
        a[key]=value;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */