class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();
        map <char, int> m;
        vector <int> ans;
        int per_char = 0;
        
        for (char c : p) {
            if (++m[c] == 1) {
                per_char++;
            }
        }
        
        auto add = [&](char c) {
            m[c]--;
            if (m[c] == 0)
                per_char--;
            if (m[c] == -1)
                per_char++;
        };
        
        auto rem = [&](char c) {
            m[c]++;
            if (m[c] == 0)
                per_char--;
            if (m[c] == 1)
                per_char++;
        };
        
        for (int i = 0; i < min(n2, n1); i++) {
            add(s[i]);
        }
        
        if (per_char == 0)
            ans.push_back(0);
        
        for (int i = n2; i < n1; i++) {
            add(s[i]);
            rem(s[i-n2]);
            if (per_char == 0)
                ans.push_back(i-n2+1);
        }
        
        return ans;
    }
};
