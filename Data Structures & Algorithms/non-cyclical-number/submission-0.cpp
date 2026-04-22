class Solution {
public:
    unordered_map<int,int> mp;
    bool iscyclic(int n){  
        if(n == 1) return true;
        if(mp[n] > 1) return false;
        
        int sum = 0;
        while(n > 0){
           sum += (n%10)*(n%10);
           n = n/10;
        }
        mp[sum]++;
        return iscyclic(sum);
    }
    bool isHappy(int n) {
        return iscyclic(n);

    }
};
