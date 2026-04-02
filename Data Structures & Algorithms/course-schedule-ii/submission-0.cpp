class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adjls(numCourses);
        for(auto it : prerequisites){
            indeg[it[0]]++;
            adjls[it[1]].push_back(it[0]);
        }
        queue<int> q; 
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adjls[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        return (numCourses == ans.size()) ? ans : vector<int>{};
        
    }
};
