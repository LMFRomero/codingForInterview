int arrayMaxConsecutiveSum2(std::vector<int> inputArray) {
    int sum;
    int max;

    sum = max = *(inputArray.begin());

    for (auto it = inputArray.begin() + 1; it != inputArray.end(); it++) {
        sum = (sum + *it < *it) ? *it : sum + *it;
        if (sum > max) max = sum;
    }

    return max;
}
