class Solution {
public:
    bool canJump(vector<int>& nums) {
        pair <int, int> interval{0,0};
        int size = nums.size();
        
        if (size == 1) return true;
        
        while (true) {
            int can_reach = -1;
            for (int i = interval.first; i <= interval.second; i++) {
                can_reach = max(can_reach, i + nums[i]);
            }
            
            interval = {interval.second+1, can_reach};
            if (interval.first > interval.second) return false;
            if (interval.second >= size-1) return true;
        }
    }
};
