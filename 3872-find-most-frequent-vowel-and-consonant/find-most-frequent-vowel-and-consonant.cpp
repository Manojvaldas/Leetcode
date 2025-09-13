class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mpp;
          string vowels = "aeiou";

        for(char c : s){
            if(isalpha(c)){
                c = tolower(c);
                mpp[c]++;
            }
        }

        int maxVowelFreq = 0, maxConsonantFreq = 0;

        for(auto& [ch, count] : mpp){
            if(vowels.find(ch) != string::npos){
                maxVowelFreq = max(maxVowelFreq, count);
            }else{
                maxConsonantFreq = max(maxConsonantFreq, count);
            }
        }
        return maxVowelFreq + maxConsonantFreq;
    }
};