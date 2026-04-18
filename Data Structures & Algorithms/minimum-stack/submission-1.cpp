class MinStack {
public:
    
    stack<pair<int, int>> st;  // pair of int and  min seen till now
    
    MinStack() {
       
    }
    
    void push(int val) {
        int mintillnow = 0;
        if(!st.empty() &&  val < st.top().second){
            mintillnow = val;
        }
        else if(!st.empty()){
            mintillnow = st.top().second;
        }
        else if(st.empty()) mintillnow = val;
        st.push({val, mintillnow}); 
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
