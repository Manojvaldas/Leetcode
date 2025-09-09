class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i< n;i++){
            int num = nums[i];
            int moreNeeded = target - num;
            //find the remaining target in the map
            if(mpp.find(moreNeeded) != mpp.end()){
                return {mpp[moreNeeded],i};
            }
            mpp[num] = i;
        }
        //if the target is not found 
        return {-1, -1};
    }
};