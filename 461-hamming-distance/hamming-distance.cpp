class Solution {
public:
    int hammingDistance(int x, int y) {
        int d = x ^ y;
        int count = 0;
        while(d){
            d = d&(d-1);
            count++;
        }
        return count;
    }
};