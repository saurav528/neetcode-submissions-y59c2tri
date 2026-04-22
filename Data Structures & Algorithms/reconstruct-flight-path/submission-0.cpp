class Solution {
private: 
    bool dfs(string src,  unordered_map<string, vector<string>>& adjmap, 
    vector<string>& ans, int len){
        if(ans.size() == len+1) return true;
        if(adjmap.find(src) == adjmap.end()) return false;

        vector<string> temp = adjmap[src];
        for(int i = 0; i < temp.size(); i++){
            string v = temp[i];
            adjmap[src].erase(adjmap[src].begin()+i);
            ans.push_back(v);
            if(dfs(v, adjmap, ans, len)) return true;
            ans.pop_back();
            adjmap[src].insert(adjmap[src].begin()+i, v);

        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjmap;

        sort(tickets.begin(), tickets.end());

        for(auto ticket : tickets){
            adjmap[ticket[0]];
        }
        for(int i = 0; i < tickets.size(); i++){
            adjmap[tickets[i][0]].push_back(tickets[i][1]);
        }
        int len = tickets.size();
        vector<string> ans;
        ans.push_back("JFK");
        dfs("JFK", adjmap, ans, len);
        return ans;



        
    }
};
