class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> found;
        int n = triplets.size();
        for(auto it : triplets){
            if(it[0] > target[0] || it[1] > target[1] || it[2] > target[2]){
                continue;
            }
            for( int i = 0; i< 3; i++){
                if(it[i] == target[i]){
                    found.insert(i);
                }
            }

        }
        if(found.size() == 3){
        return true;}
        else return false;
        
    }
};
