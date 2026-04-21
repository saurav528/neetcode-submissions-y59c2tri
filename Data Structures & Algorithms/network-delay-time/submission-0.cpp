class Solution {
public:
 
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjlist(n+1);
        for(auto it : times){
            adjlist[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[0] = 0;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int edgewt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adjlist[node]){
                int distance = edgewt + it.second;
                int adjnode = it.first;
                if(distance < dist[adjnode]){
                    dist[adjnode] = distance;
                    pq.push({distance, adjnode});
                }
            }
        }
        int maxi = INT_MIN;
        for(int k = 0; k < dist.size(); k++){
            if(dist[k] == INT_MAX) return -1;
            maxi = max(maxi, dist[k]);
        }
        return maxi;
       


    }
};
