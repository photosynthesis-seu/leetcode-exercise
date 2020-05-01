class MyStack {
public:
    queue<int> res;
    /** Initialize your data structure here. */
    MyStack() = default;
    
    /** Push element x onto stack. */
    void push(int x) {
        res.push(x);
        for(int i=0;i<res.size()-1;i++){
            res.push(res.front());
            res.pop();
        }

    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = res.front();
        res.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return res.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return res.empty();
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
