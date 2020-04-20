class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;
        
        int low = 0; int high = n-1;
        int first = nums[0];
        
        while (low <= high) {
            int mid = low + (high-low)/2;
            int value = nums[mid];
            
            if (target == value)
                return mid;
            
            bool value_big = (value >= first);
            bool target_big = (target >= first);
            
            if (value_big == target_big) {
                if (value >= target) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            else {
                if (value_big) {
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        } 
        
        return -1;
        
        
    }
};
