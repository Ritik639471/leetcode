class MyStack {
private:
    queue<int>stack;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        stack.push(-1);
        stack.push(x);
        while(stack.front()!=-1){
            stack.push(stack.front());
            stack.pop();
        }
        stack.pop();
    }
    
    int pop() {
        int n=stack.front();
        stack.pop();
        return n;
    }
    
    int top() {
        return stack.front();
    }
    
    bool empty() {
        return stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */