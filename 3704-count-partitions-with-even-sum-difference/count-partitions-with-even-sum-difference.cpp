class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;
        // If total sum is even → all (n-1) splits valid; otherwise none
        return (total % 2 == 0) ? nums.size() - 1 : 0;
    }
};
