class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sSize = s.length(), tSize = t.length();
        if (tSize == 0) {
            if (sSize == 0)
                return true;
            
            return false;
        }
        
        int i = 0;
        
        for (char c : t) {
            if (s[i] == c)
                i++;
            
            if (i == sSize)
                return true;
        }
        
        
        return false;
    }
};
