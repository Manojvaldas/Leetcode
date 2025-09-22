class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int maxFrequency  = 0;
        for(auto [num, frequency] : mpp) {
            maxFrequency = max(maxFrequency, frequency);
        }
        int frequencyOfMaxFrequency = 0;
        for(auto [num, frequency] : mpp){
            if(frequency == maxFrequency){
                frequencyOfMaxFrequency++;
            }
        }
        return frequencyOfMaxFrequency * maxFrequency;
    }
};