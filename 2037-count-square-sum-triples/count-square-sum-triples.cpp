class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for(int a = 1; a<=n; a++) {
            for(int b = 1; b<=n; b++) {
                //to avoid potential floating point inaccuracies, and using
                //the fact that the gap between consecutive perfect squares is always greater than 1,
                // we can  safely use sqrt(a*a + b* b + 1.0) instead of sqrt(a* a + b* b);
                int c = int(sqrt(a*a + b* b + 1.0));
                if(c<=n && c*c == a*a + b*b) {
                    res++;
                }
            }
        }
        return res;
    }
};