class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size(); 
       
        sort(nums.begin(), nums.end());
        
        int i = nums[0];
        for(i=1;i<n;i++ ){
            if(nums[i] == nums[i-1]){
                return nums[i];
            }
        }
        return -1;
    }
};