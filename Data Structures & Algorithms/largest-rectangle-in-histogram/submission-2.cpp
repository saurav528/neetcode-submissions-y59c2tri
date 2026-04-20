class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        if(heights.size() == 0) return maxarea;
        /*for(int i = 0; i < heights.size(); i++){
            int h = heights[i];
            int r = i , l = i -1 ;
            int w = 0;
            while(r < heights.size()){
                  if(r == l) {
                    w = 1;
                    maxarea = max(maxarea, h*w); 
                    r++;
                    continue;
                    }
                  if(heights[r] >= h) {
                    w++;
                    r++;
                  }
                  if(heights[r] < h) {
                    break;
                  }                 
            }
            while(l >= 0){
                  if(r == l) {
                    w = 1;
                    maxarea = max(maxarea, h*w); 
                    r++;
                    continue;
                    }
                  if(heights[l] >= h) {
                    w++;
                    l--;
                  }
                  if(heights[l] < h) {
                    break;
                  }                 
            }
            maxarea = max(maxarea, h*w);
            

        }*/
        stack<pair<int,int>> st;
        st.push({0, heights[0]});
        for(int i = 1; i < heights.size(); i++){
            
            if(st.top().second <= heights[i]){
                st.push({i, heights[i]});
            }
            else{
                int cnt = i;
                while(!st.empty() && st.top().second > heights[i]){
                    int h = st.top().second, w = i - st.top().first;
                    maxarea = max(maxarea, h*w);
                    cnt = st.top().first;
                    st.pop();
                    
                }
                st.push({cnt, heights[i]});
            }
        }
        int n = heights.size();
        while(!st.empty()){
            int area = st.top().second*(n - st.top().first);
            maxarea = max(area, maxarea);
            st.pop();
        }

        return maxarea;
        
    }
};
