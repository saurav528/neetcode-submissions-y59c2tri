class dsu {
    vector<int> parent, size;
public:
    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; i++) parent[i] = i;
    }
    int findparent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findparent(parent[u]);
    }
    void unionbysize(int u, int v){
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else if(size[ulp_u] == size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int,int>>> adj;
        for(int i = 0; i < points.size(); i++){
            for(int j = i; j < points.size(); j++){
                int dist = abs(points[i][0] - points[j][0]) + 
                 abs(points[i][1] - points[j][1]);
                 adj.push_back({dist, {i,j}});
            }
        }
        sort(adj.begin(), adj.end());
        int sum =  0;
        dsu ds(points.size());
        for(int k = 0; k < adj.size(); k++){
            int i = adj[k].second.first;
            int j = adj[k].second.second;
            int wt = adj[k].first;
            if(ds.findparent(i) == ds.findparent(j)){
                continue;
            }

            ds.unionbysize(i,j);
            sum += wt;
        }
        return sum;




        
    }
};
