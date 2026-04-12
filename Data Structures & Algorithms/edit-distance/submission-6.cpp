class Solution {
public:
    int f(int i, int j, string word1, string word2, vector<vector<int>> &dp){
        if(j == 0) return i;
        if(i == 0) return j;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i-1] == word2[j-1]){
            return dp[i][j] = 0 + f(i-1, j-1, word1, word2, dp);
        }
        else{
            return dp[i][j] = 1+ min({f(i-1, j-1, word1, word2, dp), f(i, j-1, word1, word2, dp), f(i-1, j, word1, word2, dp)});
        } // min(replace,insert, delete)
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        if(n == 0) return m;

       // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // base case for tabulation 
        // for(int i = 0; i <= n; i++) dp[i][0] = i;
         //for(int j = 0; j <= m; j++) dp[0][j] = j;
// Space optimization
         vector<int> prev(m+1, 0);
         vector<int> cur(m+1, 0);
         for(int i = 0; i <= m; i++) prev[i] = i;
         // nested loops
 
         for(int i = 1; i <= n; i++){  
            cur[0] = i;
            for(int j = 1; j <= m; j++){
                if(i == 0 || j == 0) continue;
                if(word1[i-1] == word2[j-1]){
                     cur[j] = 0 + prev[j-1];
                }
                else{
                    cur[j] = 1+ min( prev[j-1],  min(cur[j-1],  prev[j]));
                } // min(replace,insert, delete)
            }
            prev = cur;
         }

         return prev[m];
       // return f(word1.length(), word2.length(), word1, word2, dp);
    }
};
