class dsu{
    vector<int> size, parent;
    public: 
    dsu(int n ){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i<= n; i++){
            parent[i] = i;        }
    }
    int findpar(int node){
        if(node == parent[node]) return node;
        else{
            return parent[node] = findpar(parent[node]);
        }
    }
    bool ubs(int u, int v){
        int up_u = findpar(u);
        int up_v = findpar(v);
        if(up_u == up_v) return true;
        else if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];

        }
        return false;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        dsu ds(edges.size());
        for(auto edge : edges){
           if (ds.ubs(edge[0], edge[1])) {
            ans.push_back(edge[0]);
            ans.push_back(edge[1]);
            return ans;
        }}

        
        
    }
};
