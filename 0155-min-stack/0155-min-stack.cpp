class MinStack {
private:
    stack<int>st;
public:
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            st.push(val);
        }else{
            int n=min(val,st.top());
            st.push(val);
            st.push(n);
        }
    }
    
    void pop() {
        st.pop();
        st.pop();
    }
    
    int top() {
        int c=st.top();
        st.pop();
        int n=st.top();
        st.push(c);
        return n;
    }
    
    int getMin() {
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */