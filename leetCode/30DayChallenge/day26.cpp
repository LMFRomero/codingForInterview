class Solution {
    map <pair<int, int>, int> m;
    string str1, str2;
    
    int my_lcs (int len1, int len2) {
        if (len1 == 0 or len2 == 0)
            return 0;
        
        pair<int, int> state = {len1, len2};
        auto it = m.find(state);
        if (it != m.end())
            return it->second;
        
        if (str1[len1-1] == str2[len2-1])
            return m[state] = 1 + my_lcs(len1-1, len2-1);
        
        return m[state] = max(my_lcs(len1-1, len2), my_lcs(len1, len2-1));
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        str1 = text1;
        str2 = text2;
        
        return my_lcs(text1.length(), text2.length());
    }
};
