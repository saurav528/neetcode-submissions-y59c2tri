class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
         
        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        
        while(!q.empty()){
            
                string s = q.front().first;
                int l = q.front().second;
                q.pop();

                int nxtlevel = l+1;

                if( s == endWord) return l;
                
                for(int i = 0; i < s.size(); i++){
                    char original = s[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        s[i] = c;
                        if(st.find(s) != st.end()){
                            q.push({s, nxtlevel});
                            st.erase(s);
                        }
                    }
                    s[i] = original;
                }
            
        }
        return 0;
        
    }
};
