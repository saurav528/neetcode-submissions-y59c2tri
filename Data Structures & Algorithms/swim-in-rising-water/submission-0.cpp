class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0}); 
        vis[0][0] = 1;
        int ans = 0;
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!pq.empty()){
            int maxi = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            if(r == n -1 && c == m-1){ans = maxi; break;}
            pq.pop();
            for(auto it : directions){
                int rnew = r + it[0];
                int cnew = c + it[1];
                if(rnew < 0 || rnew >= n || cnew < 0 || cnew >=m || vis[rnew][cnew] == 1 ) continue;
                pq.push({max(grid[rnew][cnew], maxi), rnew, cnew});
                vis[rnew][cnew] = 1;
            }
            
        }
        return ans;
        
    }
};
