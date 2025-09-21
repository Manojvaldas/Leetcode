class Solution {
public:
    char findTheDifference(string s, string t) {
        int xor_sum = 0;
        for(int i =0;i<s.size();i++){
            xor_sum ^= s[i];
        }
        for(int i=0;i<t.size();i++){
            xor_sum^=t[i];
        }
        return (char) xor_sum;
    }
};