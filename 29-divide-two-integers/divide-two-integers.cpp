class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;

        long long n = abs((long long) dividend);
        long long d = abs((long long) divisor);
        long long ans = 0;
        while(n >= d){
            long long cnt = 0;
            while(n >=(d*pow(2,cnt+1))){
                cnt++;
            }
            ans += pow(2, cnt);
            n -= d*pow(2, cnt);
        }

        if(ans > INT_MAX && sign) return INT_MAX;
        if(ans > INT_MAX && !sign) return INT_MIN;

        return sign ? ans : -ans;
    }
};