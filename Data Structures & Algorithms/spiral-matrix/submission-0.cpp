class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, left = 0, right = matrix[0].size(), bottom = matrix.size();
        while(top < bottom && left < right){
            // move left to traverse top row

            for(int i = left; i < right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            
            // move down along right row
           for(int i = top; i< bottom; i++){
                res.push_back(matrix[i][right-1]);
            }
            right--;
            if(!(top < bottom && left < right)) break;
            // traverse bottom column 
           for(int i = right-1; i >= left; i--){
                res.push_back(matrix[bottom-1][i]);          
            }
             bottom--;
            // go up across 
            for(int i = bottom-1; i >= top; i--){
                res.push_back(matrix[i][left]);          
            }
            left++;
        }
        return res;
        
    }
};
