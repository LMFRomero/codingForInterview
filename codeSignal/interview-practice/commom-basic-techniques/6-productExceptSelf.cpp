int productExceptSelf(std::vector<int> nums, int m) {
    vector <int> answer;
    answer.push_back(1);
    
    int product = nums[0];
    
    int sum = 0;
    int size = nums.size();

    for (int i = 1; i < size; i++) {
        product = (product%m < 0) ? product : product%m;
        answer.push_back(product);
        product *= nums[i];
    }

    product = nums[size-1];

    for (int i = size-2; i >= 0; i--) {
        product = (product%m < 0) ? product : product%m; 
        answer[i] *= product;
        answer[i] = (answer[i]%m < 0) ? answer[i] : answer[i]%m;
        product *= nums[i]%m;
    }

    for (int i = 0; i < size; i++) {
        int tmp = answer[i];
        sum += (tmp < 0) ? tmp+m : tmp;
    }

    sum %= m;

    return (sum < 0) ? sum+m : sum;

}
