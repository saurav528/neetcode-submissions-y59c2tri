class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       /* vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            for(int j = i + 1; j < temperatures.size(); j++){
                if(temperatures[j] > temperatures[i]){
                    result[i] = j - i;
                    break;
                }
            }
        }
        return result;
*/     vector<int> result(temperatures.size(), 0);
       stack<pair<int, int>> st;
       st.push({temperatures[0], 0});
       for(int i = 1; i< temperatures.size(); i++){
           if(temperatures[i] <= st.top().first){ st.push({temperatures[i], i});}
           else{
            while(!st.empty() && st.top().first < temperatures[i]){
                result[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
           }
       }
       return result;
       
    }
};
