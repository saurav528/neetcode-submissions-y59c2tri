class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> arr(26,0);
        for(int i = 0; i < tasks.size(); i++){
            arr[tasks[i] - 'A']++;
        }
        priority_queue<int> pq;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > 0) pq.push(arr[i]);
        }
        int time = 0;
        queue<pair<int, int>> q;
        while(!pq.empty() || !q.empty()){
            
            time++;
            if(pq.empty()){
                time = q.front().second;
            }
            else{
                int  top = pq.top();
                pq.pop();
                if(top - 1 > 0) {
                    q.push({top - 1, time + n});
                }
            }
            if(!q.empty() && time == q.front().second){
                
                    pq.push(q.front().first);
                    q.pop();
                
            }

        }
        return time;
    }
};
