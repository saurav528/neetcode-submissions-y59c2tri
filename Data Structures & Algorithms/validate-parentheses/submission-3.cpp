class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {st.push(s[i]); continue;}
            else{
                
                    char c = st.top();
                    if(!st.empty() && ((c == '(' && s[i] == ')') || (c == '{' && s[i] == '}') 
                    || (c == '[' && s[i] == ']') )){
                        st.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
            }   
        }
        return (st.empty()) ? true : false;
        
    }
};
