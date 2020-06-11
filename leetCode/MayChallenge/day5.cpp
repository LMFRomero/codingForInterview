class Solution {
public:
    int firstUniqChar(string s) {
        map <char, int> m;
        
        for (char c : s)
            m[c]++;
        
        int size = s.size();
        
        for (int i = 0; i < size; i++)
            if (m[s[i]] == 1) return i;
        
        return -1;
    }
};
