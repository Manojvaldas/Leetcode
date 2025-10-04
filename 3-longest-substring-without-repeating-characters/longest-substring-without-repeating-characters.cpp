class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashLen = 256;
        int hash[hashLen];
        for(int i =0;i<hashLen;i++){
            hash[i] = -1;
        }
        int left = 0, right = 0, maxLen = 0;

        while(right < s.size()){
            if(hash[s[right]] != -1){
                left = max(hash[s[right]]+1, left);
            }
            int length = right - left + 1;
            maxLen = max(maxLen, length);

            hash[s[right]] = right;
            right++;
        }
        return maxLen;
    }
};