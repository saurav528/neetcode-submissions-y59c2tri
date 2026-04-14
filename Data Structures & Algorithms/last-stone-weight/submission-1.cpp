class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      // max heap
        priority_queue<int> pq;
        for(int wt : stones){
            pq.push(wt);
        }
        while(pq.size() > 1){
            int st1 = pq.top();
            pq.pop();
            int st2 = pq.top();
            pq.pop();
            if(st1 == st2) continue;
          
            
            if(st1 < st2) pq.push(st2 - st1);
            if(st1 > st2) pq.push(st1 - st2);
        }
        return (pq.size() == 1) ? pq.top() : 0;
        
    }
};
