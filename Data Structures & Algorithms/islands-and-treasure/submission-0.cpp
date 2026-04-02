class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i< grid.size(); i++ ){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        
        while(!q.empty()){
            int length = q.size();
            for(int i = 0; i < length; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                int delx[] = {-1,0,1,0};
                int dely[] = {0,-1,0,1};
                for(int k = 0; k < 4; k++){
                    if(x+delx[k] >= 0 && x+delx[k] < grid.size() && y+dely[k] >= 0 && y+dely[k] < grid[0].size() && grid[x+delx[k]][y+dely[k]] == 2147483647){
                        grid[x+delx[k]][y+dely[k]] = grid[x][y] + 1;
                        q.push({x+delx[k],y+dely[k]});
                    }
                }
            }
           
        }
        
    }
};
