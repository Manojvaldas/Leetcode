class Solution {
public:
    bool isHappy(int n) {
        while(n != 1 && n!=4){
            int result = 0;
            while(n != 0) {
                int ld = n%10;
                result += pow(ld, 2);
                n/=10;
            }
            n = result;
        }
        return n == 1;  
    }
};