class Solution {
public:
    string reverseVowels(string s) {
        string word = s;
        int i =0;
        int j = s.size()-1;
        string vowels = "aeiouAEIOU";
        while(i<j){
            while(i < j && vowels.find(word[i]) == string::npos){
                i++;
            }
            while(i < j && vowels.find(word[j]) == string::npos){
                j--;
            }
            swap(word[i],word[j]);
            i++;
            j--;
            
            
        }
        return word;
    }
};