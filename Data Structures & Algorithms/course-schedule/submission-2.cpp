class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjls(numCourses);
        vector<int> indeg(numCourses, 0);
        for(auto it : prerequisites){
            adjls[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adjls[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        return (topo.size() == numCourses) ? true : false;
    }
};
