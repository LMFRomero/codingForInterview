class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1, mid;

        while (hi >= lo) {
            mid = (hi+lo)/2;
            
            if (nums[mid] == target)
                return mid;
            
            else if (nums[mid] > target)
                hi = mid-1;
            
            else
                lo = mid+1;
        }
    
        mid = (lo+hi)/2;

        return (nums[mid] > target) ? mid : mid+1;
    }
};
