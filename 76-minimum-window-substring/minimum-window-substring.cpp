class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int sIndex = -1;
        int count = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX
;        for(char c: t){
            hash[c]++;
        }
        while(right < s.size()){
            if(hash[s[right]]>0) {
                count++;
            }
            hash[s[right]]--;
            while(count == t.size()){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    sIndex = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0){
                    count--;
                }
                left++;
            }
            right++;

        }
        return (sIndex == -1) ? "":s.substr(sIndex, minLen);
    }
};