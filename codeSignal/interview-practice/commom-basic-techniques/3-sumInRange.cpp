int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries) {
    int sum = 0;
    const int mod = 1000000007;

    for (auto it = nums.begin(); it != nums.end(); it++) {
        sum += *it;
        if (sum >= mod) sum -= mod;
        else if (sum < 0) sum += mod;
        *it = sum;
    }

    sum = 0;

    for (auto it = queries.begin(); it != queries.end(); it++) {
        sum += nums[(*it)[1]] - (((*it)[0]) ? nums[(*it)[0]-1] : 0);
        if (sum >= mod) sum -= mod;
        else if (sum < 0) sum += mod;
    }

    return (sum < 0) ? sum + mod : sum;
}
