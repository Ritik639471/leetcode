class SmallestInfiniteSet {
public:
    int i;
    map<int,bool>m;
    SmallestInfiniteSet() {
        i=1;
    }
    
    int popSmallest() {
        int j=i;
        i+=1;
        while(m[i]) {i++;}
        m[j]=true;
        return j; 
    }
    
    void addBack(int num) {
        if(i>num){
            i-=1;
            while(i!=num) m[i--]=true;
        }
        m[num]=false;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */