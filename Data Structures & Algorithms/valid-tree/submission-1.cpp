class Solution {
private:
      bool detectcycle(int node, int parent , vector<int> &vis, vector<vector<int>> &adjls){
        vis[node] = 1;
        for(auto adjnode : adjls[node]){
            if(!vis[adjnode]){
                if(detectcycle(adjnode, node, vis, adjls)) return true;
            }
            else if(adjnode != parent){
                return true;
            }
        }
        return false;
      }
public:
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjls(n);
        vector<int> vis(n,0);
        for(auto it : edges){
            adjls[it[0]].push_back(it[1]);
            adjls[it[1]].push_back(it[0]);
        }
        bool cycle = false;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(detectcycle(i, -1, vis, adjls)) cycle = true;
            }
        }
        if(cycle == false && n-1 == edges.size()) return true;
        return false;
         
    }
};
