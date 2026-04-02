class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adjls){
        vis[node] = 1;
        for(auto it : adjls[node]){
            if(!vis[it]){
                 dfs(it, vis, adjls);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjls(n);
        for(auto it : edges){
            adjls[it[0]].push_back(it[1]);
            adjls[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adjls);
            }
        }
        return cnt;

    }
};
