std::vector<int> findLongestSubarrayBySum(int s, std::vector<int> arr) {
    int low, high, maxLow, maxHigh;
    low = high = maxLow = 0;
    maxHigh = -1;
    int sum = 0;
    int size = arr.size();
    bool hasFound = false;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
        high = i;
        while (sum > s) {
            sum -= arr[low];
            low++;
        }

        if (sum == s) {
            hasFound = true;
            if (high - low > maxHigh - maxLow) {
                maxHigh = high;
                maxLow = low;
            }
        }
    }

    if (!hasFound) return {-1};

    return {maxLow+1, maxHigh+1};
}

