class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map <int, int> m;
        m[0] = 1;
        
        int sum = 0;
        int counter = 0;
        
        for (int x : nums) {
            sum += x;
            counter += m[sum-k];
            m[sum]++;
        }
        
        return counter;
    }
};
