class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        for(int i = 0; i < heights.size(); i++){
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
            

        }
        return maxarea;
        
    }
};
