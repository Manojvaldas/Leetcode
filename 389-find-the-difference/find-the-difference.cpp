class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        int i = 0;
        int n = s.size();
        int m = t.size();
        
        while(i<n){
            if(s[i] != t[i])
            {
                return t[i];
            } 
            i++;
        }
        return t[m-1];
    }
};