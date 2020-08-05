class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mid;
        
        if (hi == 0) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[hi] != nums[hi-1]) return nums[hi];
        
        while (lo <= hi) {
            mid = lo+(hi-lo)/2;
            
            if (nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1])
                return nums[mid];
            
            if (mid%2 == 0 and nums[mid] != nums[mid+1] or mid%2 == 1 and nums[mid] != nums[mid-1])
                hi = mid-1;
            else
                lo = mid+1;
        }
        
        return -1;
    }
};
