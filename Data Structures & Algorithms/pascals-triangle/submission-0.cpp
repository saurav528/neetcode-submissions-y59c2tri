class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
              vector<int> row;
              int val = 1;
              row.push_back(val);
              for(int r = 1; r <= i; r++){
                val = val * (i-r+1)/r;
                row.push_back(val);
              }
              ans.push_back(row);
        }
        return ans;
    }
};