class Solution {
public:
    int lcs(int ind1, int ind2, string& s1, string& s2, vector<vector<int>> &memo){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(memo[ind1][ind2] != -1) return memo[ind1][ind2];
        if(s1[ind1] == s2[ind2]){return memo[ind1][ind2] = 1 + lcs(ind1-1, ind2-1, s1, s2, memo);}
        else{
            return memo[ind1][ind2] = max(lcs(ind1-1, ind2, s1, s2, memo), lcs(ind1, ind2-1, s1, s2, memo));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length(), vector<int>(text2.length(), -1));
        return lcs(text1.length()-1, text2.length()-1, text1, text2, memo);
        
    }
};
