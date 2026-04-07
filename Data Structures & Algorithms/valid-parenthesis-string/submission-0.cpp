class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stp;
        stack<int> sts;
        for(int i =0; i < s.length(); i++){
            if(s[i] == '(') stp.push(i);
            if(s[i] == '*') sts.push(i);
            if(s[i] == ')'){
                if(!stp.empty()) stp.pop();
                else if(!sts.empty()) sts.pop();
                else if(stp.empty() && sts.empty()) return false;
            }
        }
        while(!stp.empty() && !sts.empty()){
            int p = stp.top();
            int s = sts.top();
            stp.pop();
            sts.pop();
            if(p > s) return false;
        }
        return (stp.empty()) ? true : false;
    }
};
