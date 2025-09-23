class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int r = 0;
        int ans = 0;
        while(r<n){
            ans+=nums[r];
            r+=2;
        }
        return ans;
    }
};