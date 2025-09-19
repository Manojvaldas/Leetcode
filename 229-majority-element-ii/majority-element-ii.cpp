class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<int> arr;
        for(auto it : mpp){
            int ele = it.first;
            int cnt = it.second;
             if(cnt>n/3) arr.push_back(ele);
        }
       
        return arr;
    }
};