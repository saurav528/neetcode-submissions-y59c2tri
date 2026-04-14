class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0], y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist, i});
        }
        vector<vector<int>> ans;
        for(int i = 1; i <= k; i++){
            pair<int,int> top = pq.top();
            pq.pop();
            ans.push_back({points[top.second][0], points[top.second][1]});
            
        }
        return ans;
    }
};
