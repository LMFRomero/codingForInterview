class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int max = nums[0];
        
        for (auto it = nums.begin() + 1; it != nums.end(); it++) {
            sum = (sum + *it > *it) ? sum + *it : *it;
            max = (sum > max) ? sum : max;
        }
        
        return max;
    }
};
