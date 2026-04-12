class Solution {
public:
 /*   int f(int i, int j, string &s, string& t, vector<vector<int>>& dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
       
        if(s[i-1] == t[j-1]){
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        }
        else{
            return dp[i][j] = f(i-1, j, s, t, dp);
        }
        
    }*/
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if(m > n) return 0;
    //    vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
      //  for(int i = 0; i < n+1; i++) dp[i][0] = 1;
        //for(int j = 1; j < m+1; j++) dp[0][j] = 0;
         vector<int> prev(m+1, 0);
         prev[0] = 1;

        for(int i = 0; i < n+1; i++){
            vector<int> cur(m+1, 0);
            cur[0] = 1;
            for(int j = 0; j < m+1; j++){
                if(i == 0 || j == 0) continue;
                    
            if(s[i-1] == t[j-1]){
                cur[j] = prev[j-1] + prev[j];
            }
            else{
                cur[j] = prev[j];
            }

            }
            prev = cur;
        }
        return prev[m];

     //   return f(s.length(), t.length(), s, t, dp);

    }
};
