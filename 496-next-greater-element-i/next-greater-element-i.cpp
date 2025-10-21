class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nge;
        for(int i =0;i<n;i++){
            int next = -1;
            bool found = false;
            for(int j =0;j<m;j++){
                if(nums2[j] == nums1[i]) found = true;
                if(found && nums2[j] > nums1[i]){
                    next = nums2[j];
                    break;
                }
            }
            nge.push_back(next);
        }
        return nge;
    }
};