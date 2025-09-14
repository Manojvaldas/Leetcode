class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> arr;
        unordered_map<int, int> mpp;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        for(auto it :  mpp){
            if(it.second == 1) arr.push_back(it.first);
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};