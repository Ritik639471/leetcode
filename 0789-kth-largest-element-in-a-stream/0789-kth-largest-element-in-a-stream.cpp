class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k,s;
    KthLargest(int k, vector<int>& nums) {
       this->k=k;
       s=0;
       for(auto c: nums){
        s++;
        pq.push(c);
        if(s>k) {pq.pop();s--;}
       }
    }
    
    int add(int val) {
        s++;
        pq.push(val);
        if(s>k) {pq.pop();s--;}
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */