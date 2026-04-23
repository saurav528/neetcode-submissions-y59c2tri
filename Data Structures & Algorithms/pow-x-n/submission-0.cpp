class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1; 

        for(int i = 1; i <= abs(n); i++){
            ans = ans*x;
        }
        return (n < 0) ? 1/ans : ans;
    }
};
