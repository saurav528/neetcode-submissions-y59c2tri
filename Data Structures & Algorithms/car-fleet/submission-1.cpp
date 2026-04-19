class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<pair<int, int>> pairs;
        for(int i = 0; i < position.size(); i++){
            pairs.push_back({position[i], speed[i]});
         //   pairs[i].second = speed[i];
        }
        sort(pairs.rbegin(), pairs.rend());

        for(auto p : pairs){
            double time = (double)(target - p.first) / p.second;
            if(st.empty()) {st.push(time); continue;}
            if(time <= st.top()) continue;
            else{
                st.push(time);
            }
        }
        return st.size();
        
    }
};
