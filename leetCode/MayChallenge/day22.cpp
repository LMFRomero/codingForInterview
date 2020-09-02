class Solution {
public:
    string frequencySort(string s) {
        map <char, int> m;
        vector <pair<int, char>> v;
        
        for (char c : s)
            m[c]++;
        
        for (auto it = m.begin(); it != m.end(); it++) {
            v.emplace_back(it->second, it->first);
        }
        
        sort(v.rbegin(), v.rend());
        
        string ans = "";
        
        for (auto it = v.begin(); it != v.end(); it++) {
            for (int i = 0; i < it->first; i++)
                ans += it->second;
        }
        
        return ans;
    }
};
