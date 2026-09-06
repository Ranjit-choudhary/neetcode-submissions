class MinStack {
public:
        vector<int> st;
        vector<int> stmin;
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if(stmin.empty()) stmin.push_back(val);
        else{
            int x= stmin.back();
            if(val>x) stmin.push_back(x);
            else stmin.push_back(val);
        }
    }
    
    void pop() {
        st.pop_back();
        stmin.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return stmin.back();
    }
};
