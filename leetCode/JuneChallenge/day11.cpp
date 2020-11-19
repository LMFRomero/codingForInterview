class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        
        for (int n : nums) {
            switch (n) {
                case 0:
                    r++;
                    break;
                case 1:
                    w++;
                    break;
                case 2:
                    b++;
                    break;
            }
        }
        
        int i = 0;
        
        while (r--)
            nums[i++] = 0;
        while (w--)
            nums[i++] = 1;
        while (b--)
            nums[i++] = 2;
    }
};
