class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        while (!q.empty()) q.pop();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int sz = q.size() - 1;
        while (sz--) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        int tmp = q.front();
        q.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        int sz = q.size();
        int tmp;
        while (sz--) {
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
