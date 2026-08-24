class MinStack {
private:
        stack<int>main_st;
        stack<int>min_st;
public:
    
    void push(int value) {
        main_st.push(value);

        if (min_st.empty()){
         min_st.push(value);
        }
        // elseif (value <= min_st.top()){
        //     min_st.push(value);
        // }                                   /// here two statement replaced by single statement of min () function
        // else {
        //     min_st.push(min_st.top());
        // }

        else {
            min_st.push(min(value,min_st.top()));
        }
    }
    
    void pop() {
        min_st.pop();
        main_st.pop();
    }
    
    int top() {
        return main_st.top();
    }
    
    int getMin() {
        return min_st.top();
        
    }
};
