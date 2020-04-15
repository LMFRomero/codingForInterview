class Solution {https://github.com/LMFRomero/coding_for_interview
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, size = (int) nums.size();
        vector <int> answer;
        
        for (int i = 0; i < size; i++) {
            answer.push_back(product);
            product *= nums[i];
        }
        
        product = 1;
        
        for (int i = 0; i < size; i++) {
            answer[size-1-i] *= product;
            product *= nums[size-1-i];
        }
        
        return answer;
    }
};
