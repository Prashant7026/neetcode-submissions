class MinStack {
public:
    stack<long long> st;
    stack<long long> stMin;

    MinStack() {}
    
    void push(int val) {
        st.push((long long) val);
        if(stMin.empty())   stMin.push(st.top());
        else if(!st.empty() && st.top() < stMin.top())  stMin.push(st.top());
        else{
            stMin.push(stMin.top());
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            stMin.pop();
        }
    }
    
    int top() {
        if(!st.empty())     return st.top();
        return 0;
    }
    
    int getMin() {
        if(!stMin.empty())      return stMin.top();
        else return 0;
    }
};
