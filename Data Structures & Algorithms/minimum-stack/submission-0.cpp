class MinStack {
public:
    stack<int> stk;
    stack<int> minstack;
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        if(minstack.empty() || val<=minstack.top()){
            minstack.push(val);
        }
        else
            minstack.push(minstack.top());
    }
    
    void pop() {
        stk.pop();
        minstack.pop();
    }
    
    int top() {
        int result = stk.top();
        return result;
    }
    
    int getMin() {
        int result = minstack.top();
        return result;
    }
};
