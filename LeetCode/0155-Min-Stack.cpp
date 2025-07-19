class MinStack {
        vector<vector<int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min = 0;
       
        min = getMin();
        if(min>val){
            min = val;
        }
         if(st.empty()){
            min=val;
        }
        st.push_back({val,min});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        if(st.empty()) return 0;
        return st.back()[0];
    }
    
    int getMin() {
        if(st.empty()) return 0;
        return st.back()[1];
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
