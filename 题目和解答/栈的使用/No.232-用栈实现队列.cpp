class MyQueue {
public:
    stack<int> res;
    /** Initialize your data structure here. */
    MyQueue() = default;
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        // for(int i=0;i<res.size();i++){
        //     temp.push(res.top());
        //     res.pop();
        // }存在的问题：每次res.pop()后res的大小都改变了，无法让res.size()保持原始大小！
        while(!res.empty()){
            temp.push(res.top());
            res.pop();
        }
        res.push(x);
    //     for(int j=0;j<temp.size();j++){
    //         res.push(temp.top());
    //         temp.pop();
    //     }
        while(!temp.empty()){
            res.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = res.top();
        res.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        return res.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return res.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
