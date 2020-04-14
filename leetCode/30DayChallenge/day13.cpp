class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector <int> pref;
        pref.push_back(0);
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) nums[i] = -1;
        }
        
        for (int x : nums) pref.push_back(pref.back() + x);
        
        int answer = 0;
        unordered_map <int, int> first;
        
        for (int i = 0; i < pref.size(); i++) {
            if (first.find(pref[i]) != first.end()) {
                answer = max(answer, i - first[pref[i]]);
            }
            else {
                first[pref[i]] = i;
            }
        }
        
        return answer;
    }
};
