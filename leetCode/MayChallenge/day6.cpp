class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> m;
        int n = nums.size()/2;
        
        for (int i : nums) {
            m[i]++;
        }
        
        for (auto q : m) {
            if (q.second > n) return q.first;
        }
            
        return -1;           
    }
};
