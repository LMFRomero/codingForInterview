class Solution {
    
public:
    int maxSubarraySumCircular(vector<int>& a) {
        long long ans = a[0];
        int first = 0;
        int n = a.size();
        long long cur_prefix = 0;
        vector<pair<int, long long>> s;
        s.emplace_back(-1, 0LL);
        
        for (int i = 0; i < n; i++) {
            a.push_back(a[i]);
        }
        
        for (int i = 0; i < 2*n; i++) {
            if (first < s.size() and s[first].first == i-n-1) {
                first++;
            }
            cur_prefix += a[i];
            if (first < s.size()) ans = max(cur_prefix - s[first].second, ans);
            while (first < s.size() and s.back().second >= cur_prefix)
                s.pop_back();
            
            s.emplace_back(i, cur_prefix);
        }
        return ans;
    }
};
