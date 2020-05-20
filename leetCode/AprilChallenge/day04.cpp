class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int available = 0;
        int size = nums.size();
        
        for (int num : nums) {
            if (num) {
                nums[available++] = num;
            }
        }
        
        for (; available < size; available++) {
            nums[available] = 0;
        }
    }
};
