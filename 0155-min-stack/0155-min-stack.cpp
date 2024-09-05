class MinStack {
    stack <long long> st;
    long long min ;
public:
    MinStack() {
        
    }
    
    void push(long long val) {
        if(st.empty()){
            st.push(val);
            min=val;
        }
        else{
            if(val>min) st.push(val);
            else{
                st.push(2*val-min);
                min=val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long n = st.top();
        if(n < min){
            min = (2 * min - n);
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return 0;
        }
        long long n = st.top();
        if(n > min){
            return n;
        }
        return min;
    }
    
    int getMin() {
        return min;
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